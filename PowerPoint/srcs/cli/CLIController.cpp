#include "cli/CLIController.h"
#include "cli/parsing/CommandParser.h"
#include "cli/CLIViewer.h"

#include <iostream>

using namespace ppt::cli;
using namespace ppt::core;

CLIController::CLIController(
	CLIViewer& viewer,
	CommandRegistry& registry,
	model::Presentation& presentation) : 
	m_viewer(viewer), 
	m_registry(registry), 
	m_presentation(presentation) { }

int CLIController::run()
{
	m_viewer.showWelcome();

	CommandParser parser(m_registry, m_viewer.getIStream());

	while (!m_exit)
	{
		m_viewer.showPrompt();
		try
		{
			std::unique_ptr<cmds::ICommand> cmd = parser.parseCommand();
			if (cmd)
				cmd->execute();
		}
		catch (const std::exception& e)
		{
			m_viewer.showError(e.what());
			m_viewer.resetStream();
		}
	}

	return 0;
}

void CLIController::exit() { m_exit = true; }