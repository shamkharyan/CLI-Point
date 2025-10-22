#include "model/PPModel.h"
#include "model/commands/ACommand.h"
#include "model/commands/AConfirmCommand.h"
#include "controller/CLIController.h"
#include "controller/parsing/Parser.h"
#include "CommandRegistry.h"
#include "viewer/CLIViewer.h"

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

	registerMainCommands();
	auto& context = m_model.getContext();
	Parser parser(context, m_viewer.getIStream());

	while (!context.exit)
	{
		auto name = (context.presentation) ? context.presentation->getName() : "";
		m_viewer.showPrompt(name);
		try
		{
			std::unique_ptr<ACommand> cmd = parser.parse();
			if (cmd)
				cmd->execute();
			else
				m_viewer.showInfo("Empty input");
		}
		catch (const std::runtime_error& e)
		{
			m_viewer.showError(e.what());
			m_viewer.resetStream();
		}
	}
}