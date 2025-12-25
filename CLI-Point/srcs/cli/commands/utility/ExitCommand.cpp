#include "cli/commands/utility/ExitCommand.h"
#include "cli/CLIViewer.h"

using namespace ppt::cli::cmds;

ExitCommand::ExitCommand(CLIController& controller, CLIViewer& viewer, bool force) :
	m_controller(controller),
	m_viewer(viewer),
	m_force(force)
{
}

void ExitCommand::execute()
{
	bool shouldExit = true;

	if (!m_force)
	{
		auto ans = m_viewer.askConfirmation("Do you want to exit programm?");
		shouldExit = ans && ans.value();
	}
	if (shouldExit)
		m_controller.exit();
}