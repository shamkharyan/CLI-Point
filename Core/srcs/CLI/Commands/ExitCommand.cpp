#include "ExitCommand.h"
#include "Command.h"
#include "model/AppContext.h"

ExitCommand::ExitCommand(AppContext& context) : Command(context) {}

void ExitCommand::execute()
{
	m_context.m_exit = true;
}