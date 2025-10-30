#include "cli/commands/AddSlideCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/AddSlideAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

AddSlideCommand::AddSlideCommand(std::optional<std::size_t> at, std::optional<model::utils::Color> bgColor) :
	m_at(at),
	m_bgColor(bgColor)
{
}

void AddSlideCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::AddSlideAction>(m_at, m_bgColor.value_or(utils::Color{ 255,255,255 }));
	if (action->doAction())
		manager.append(std::move(action));
}
