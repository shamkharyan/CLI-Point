#include "cli/commands/EditPresentationCommand.h"
#include "model/PPModel.h"
#include "core/actions/EditPresentationAction.h"
#include "core/ActionManager.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;

EditPresentationCommand::EditPresentationCommand(const std::optional<std::string>& name) : m_name(name) {}

void EditPresentationCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::EditPresentationAction>(m_name);
	if (action->doAction())
		manager.append(std::move(action));
}