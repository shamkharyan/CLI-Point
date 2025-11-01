#include "cli/commands/slide/DuplicateSlideCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/slide/DuplicateSlideAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

DuplicateSlideCommand::DuplicateSlideCommand(std::optional<std::size_t> at, std::optional<std::size_t> to, bool go) :
	m_at(at),
	m_to(to),
	m_goto(go)
{
}

void DuplicateSlideCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::DuplicateSlideAction>(m_at, m_to, m_goto);
	if (action->doAction())
		manager.append(std::move(action));
}
