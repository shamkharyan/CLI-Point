#include "cli/commands/utility/RedoCommand.h"
#include "model/PPModel.h"
#include "core/ActionManager.h"

using namespace ppt::cli::cmds;

void RedoCommand::execute()
{
	model::PPModel::instance().getContext().getActionManager().redo();
}