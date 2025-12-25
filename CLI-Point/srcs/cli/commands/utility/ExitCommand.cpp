#include "cli/commands/utility/ExitCommand.h"
#include "cli/CLIViewer.h"

using namespace ppt::cli::cmds;

ExitCommand::ExitCommand(
	CLIController& controller, 
	CLIViewer& viewer,
	model::Presentation& presentation, 
	bool force) :
	m_controller(controller),
	m_viewer(viewer),
	m_presentation(presentation),
	m_force(force)
{
}

void ExitCommand::execute()
{
	bool shouldExit = true;

	if (!m_force && m_presentation.isModified())
	{
		auto ans = m_viewer.askConfirmation("Unsaved changes. Do you want to exit programm?");
		shouldExit = ans && ans.value();
	}
	if (shouldExit)
		m_controller.exit();
}