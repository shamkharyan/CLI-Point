#include "core/commands/ExitCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

ExitCommand::ExitCommand(viewer::IViewer& viewer, bool force) :
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
	context.exit = shouldExit;
}