#include "cli/commands/PrevCommand.h"
#include "model/PPModel.h"
#include "core/ActionManager.h"
#include "model/AppContext.h"
#include "core/actions/PrevSlideAction.h"

#include <memory>

using namespace ppt::core;
using namespace ppt::cli::cmds;

void PrevCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::PrevSlideAction>();
	if (action->doAction())
		manager.append(std::move(action));
}