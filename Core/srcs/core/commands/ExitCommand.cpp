#include "core/commands/ExitCommand.h"
#include "core/commands/AConfirmCommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

ExitCommand::ExitCommand(AppContext& context, viewer::IViewer& viewer, bool force) :
	AConfirmCommand(context, viewer),
	m_force(force) {}

void ExitCommand::execute()
{
	if (!m_force)
	{
		auto ans = m_viewer.askConfirmation("Do you want to exit programm?");
		if (ans && ans.value())
			m_context.exit = true;
	}
	else
		m_context.exit = true;
}