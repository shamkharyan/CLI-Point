#include "cli/commands/utility/UndoCommand.h"
#include "core/ActionManager.h"

using namespace ppt::cli::cmds;

UndoCommand::UndoCommand(core::ActionManager& actionManager) :
	m_actionManager(actionManager)
{
}

void UndoCommand::execute()
{
	m_actionManager.undo();
}