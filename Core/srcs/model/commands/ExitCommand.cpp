#include "model/commands/ExitCommand.h"
#include "model/commands/AConfirmCommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include <stdexcept>

ExitCommand::ExitCommand(AppContext& context, IViewer& viewer, bool force) :
	AConfirmCommand(context, viewer),
	m_force(force) {}

void ExitCommand::execute()
{
	if (!m_force)
	{
		auto ans = m_viewer.askConfirmation("Do you want to exit programm?");
		if (ans)
			m_context.exit = true;
	}
	else
		m_context.exit = true;
}