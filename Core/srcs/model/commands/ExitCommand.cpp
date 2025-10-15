#include "model/commands/ExitCommand.h"
#include "model/commands/AConfirmCommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include <stdexcept>

ExitCommand::ExitCommand(AppContext& context, bool force) :
	AConfirmCommand(context),
	m_force(force) {}

ACommand::Result ExitCommand::execute()
{
	if (m_force)
	{
		m_context.exit = true;
		return ACommand::Result::Success;
	}
	return ACommand::Result::Confirmation;
}

ACommand::Result ExitCommand::confirm(bool ans)
{
	if (ans)
		m_context.exit = true;
	return ACommand::Result::Success;
}

std::string ExitCommand::confirmQuestion() const
{
	return "Do you want to exit programm?";
}