#include "cli/CLIController.h"
#include "cli/Parser.h"
#include "model/PPModel.h"
#include "viewer/cli/CLIViewer.h"

#include <iostream>

using namespace ppt::cli;
using namespace ppt::core;

CLIController::CLIController(viewer::cli::CLIViewer& viewer) : m_viewer(viewer) { }

void CLIController::run()
{
	auto& context = model::PPModel::instance().getContext();
	m_viewer.showWelcome();

	Parser parser(m_viewer.getIStream());

	while (!m_exit)
	{
		m_viewer.showPrompt(context.getPresentation());
		try
		{
			std::unique_ptr<cmds::ICommand> cmd = parser.parse();
			if (cmd)
				cmd->execute();
		}
		catch (const std::exception& e)
		{
			m_viewer.showError(e.what());
			m_viewer.resetStream();
		}
	}
}

void CLIController::exit() { m_exit = true; }