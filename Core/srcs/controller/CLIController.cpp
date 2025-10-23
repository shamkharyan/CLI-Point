#include "model/PPModel.h"
#include "viewer/CLIViewer.h"
#include "controller/commands/ACommand.h"
#include "controller/commands/AConfirmCommand.h"
#include "controller/CLIController.h"
#include "controller/parsing/Parser.h"
#include "controller/CommandRegistry.h"

#include <iostream>

CLIController::CLIController(PPModel& model, CLIViewer& viewer) : 
	m_model(model),
	m_viewer(viewer)
{ }

CLIController& CLIController::instance(PPModel& model, CLIViewer& viewer)
{
	static CLIController obj(model, viewer);
	return obj;
}

void CLIController::run()
{
	m_viewer.showText("PowerPoint CLI v0.1");
	auto& context = m_model.getContext();

	registerMainCommands(context, m_viewer);
	Parser parser(m_viewer.getIStream());

	while (!context.exit)
	{
		auto presentationName = (context.presentation) ? context.presentation->getName() : "";
		m_viewer.showPrompt(presentationName);
		try
		{
			std::unique_ptr<ACommand> cmd = parser.parse();
			if (cmd)
				cmd->execute();
			else
				m_viewer.showInfo("Empty input");
		}
		catch (const std::exception& e)
		{
			m_viewer.showError(e.what());
			m_viewer.resetStream();
		}
	}
}