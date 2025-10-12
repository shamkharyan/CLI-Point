#include "controller/CLIController.h"
#include "controller/parsing/Parser.h"
#include "CommandRegistry.h"
#include "model/PPModel.h"
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
	m_viewer.showPrompt("PowerPoint CLI v0.1\n");

	auto& context = m_model.getContext();
	registerMainCommands();
	Parser parser(context, m_viewer);

	while (!context.exit)
	{
		try
		{
			m_viewer.showPrompt();
			std::unique_ptr<Command> cmd = parser.parse();
			if (cmd)
			{
				cmd->execute();
				m_viewer.showInfo("OK");
			}
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

