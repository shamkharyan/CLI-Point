#include "cli/commands/presentation/RenamePresentationCommand.h"
#include "model/PPModel.h"
#include "core/actions/presentation/RenamePresentationAction.h"
#include "core/ActionManager.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;

RenamePresentationCommand::RenamePresentationCommand(const std::optional<std::string>& name) : m_name(name) {}

void RenamePresentationCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::RenamePresentationAction>(m_name);
	if (action->doAction())
		manager.append(std::move(action));
}