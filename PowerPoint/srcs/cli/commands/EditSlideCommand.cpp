#include "cli/commands/EditSlideCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/EditSlideAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

EditSlideCommand::EditSlideCommand(std::optional<std::size_t> at, std::optional<model::utils::Color> bgColor) :
	m_at(at),
	m_bgColor(bgColor)
{
}

void EditSlideCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::EditSlideAction>(m_at, m_bgColor);
	if (action->doAction())
		manager.append(std::move(action));
}
