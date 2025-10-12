#include "ExitCommand.h"
#include "Command.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include <stdexcept>

ExitCommand::ExitCommand(AppContext& context, IViewer& viewer, bool force) :
	Command(context, viewer), m_force(force) {}

void ExitCommand::execute()
{
	if (m_force)
	{
		m_context.exit = true;
		return;
	}
	auto ans = m_viewer.askConfirmation("Do you want to exit programm?");

	if (!ans.has_value())
		throw std::runtime_error("Command aborted");
	m_context.exit = ans.value();
}