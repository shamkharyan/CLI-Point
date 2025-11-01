#include "cli/commands/slide/AddSlideCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/slide/AddSlideAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

AddSlideCommand::AddSlideCommand(std::optional<std::size_t> at, std::optional<model::utils::Color> color, bool go) :
	m_at(at),
	m_color(color),
	m_goto(go)
{
}

void AddSlideCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::AddSlideAction>(m_at, m_color, m_goto);
	if (action->doAction())
		manager.append(std::move(action));
}
