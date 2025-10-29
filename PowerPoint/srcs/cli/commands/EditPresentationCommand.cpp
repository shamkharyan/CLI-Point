#include "cli/commands/EditPresentationCommand.h"
#include "model/PPModel.h"
#include "core/actions/EditPresentationAction.h"
#include "core/ActionManager.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;

void EditPresentationCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::EditPresentationAction>(m_name);
	action->doAction();
	manager.append(std::move(action));
}