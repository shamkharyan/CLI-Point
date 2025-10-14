#include "ExitCommand.h"
#include "ConfirmCommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include <stdexcept>

ExitCommand::ExitCommand(AppContext& context, bool force) :
	ConfirmCommand(context),
	m_force(force) {}

Command::Result ExitCommand::execute()
{
	if (m_force)
	{
		m_context.exit = true;
		return Command::Result::Success;
	}
	return Command::Result::Confirmation;
}

Command::Result ExitCommand::confirm(bool ans)
{
	if (ans)
		m_context.exit = true;
	return Command::Result::Success;
}

std::string ExitCommand::confirmQuestion() const
{
	return "Do you want to exit programm?";
}