#include "cli/commands/slide/GotoSlideCommand.h"
#include "model/PPModel.h"
#include "core/ActionManager.h"
#include "model/AppContext.h"
#include "core/actions/slide/GotoSlideAction.h"

#include <memory>

using namespace ppt::core;
using namespace ppt::cli::cmds;

GotoSlideCommand::GotoSlideCommand(std::size_t at) : m_at(at) {}

void GotoSlideCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::GotoSlideAction>(m_at);
	if (action->doAction())
		manager.append(std::move(action));
}