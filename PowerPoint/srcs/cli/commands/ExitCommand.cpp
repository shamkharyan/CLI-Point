#include "cli/commands/ExitCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::cli::cmds;

ExitCommand::ExitCommand(core::IController& controller, viewer::IViewer& viewer, bool force) :
	m_controller(controller),
	m_viewer(viewer),
	m_force(force) 
{}

void ExitCommand::execute()
{
	auto& context = PPModel::instance().getContext();
	bool shouldExit = true;

	if (!m_force)
	{
		auto ans = m_viewer.askConfirmation("Do you want to exit programm?");
		shouldExit = ans && ans.value();
	}
	if (shouldExit)
		m_controller.exit();
}