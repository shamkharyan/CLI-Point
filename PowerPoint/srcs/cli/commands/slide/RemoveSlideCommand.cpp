#include "cli/commands/slide/RemoveSlideCommand.h"
#include "core/ActionManager.h"
#include "core/actions/slide/RemoveSlideAction.h"
#include "model/PPModel.h"

using namespace ppt::core;
using namespace ppt::cli::cmds;

RemoveSlideCommand::RemoveSlideCommand(std::optional<std::size_t> at) : m_at(at) {}

void RemoveSlideCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::RemoveSlideAction>(m_at);
	if (action->doAction())
		manager.append(std::move(action));
}
