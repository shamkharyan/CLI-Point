#include "cli/commands/utility/RedoCommand.h"
#include "core/ActionManager.h"

using namespace ppt::cli::cmds;

RedoCommand::RedoCommand(core::ActionManager& actionManager) :
	m_actionManager(actionManager)
{
}

void RedoCommand::execute()
{
	m_actionManager.redo();
}