#include "cli/commands/NextSlideCommand.h"
#include "model/PPModel.h"
#include "core/ActionManager.h"
#include "model/AppContext.h"
#include "core/actions/NextSlideAction.h"

#include <memory>

using namespace ppt::core;
using namespace ppt::cli::cmds;

void NextSlideCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::NextSlideAction>();
	if (action->doAction())
		manager.append(std::move(action));
}