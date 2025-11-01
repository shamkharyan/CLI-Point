#include "cli/commands/slide/SetSlideColorCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/slide/SetSlideColorAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

SetSlideColorCommand::SetSlideColorCommand(std::optional<std::size_t> at, model::utils::Color color) :
	m_at(at),
	m_color(color)
{
}

void SetSlideColorCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::SetSlideColorAction>(m_at, m_color);
	if (action->doAction())
		manager.append(std::move(action));
}
