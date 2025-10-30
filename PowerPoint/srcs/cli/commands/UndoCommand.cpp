#include "cli/commands/UndoCommand.h"
#include "model/PPModel.h"
#include "core/ActionManager.h"

using namespace ppt::cli::cmds;

void UndoCommand::execute()
{
	model::PPModel::instance().getContext().getActionManager().undo();
}