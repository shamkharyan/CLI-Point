#include "cli/commands/shape/RemoveShapeCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/shape/RemoveShapeAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

RemoveShapeCommand::RemoveShapeCommand(
	std::size_t shapeId,
	std::optional<std::size_t> at) :
	m_shapeId(shapeId),
	m_at(at)
{
}

void RemoveShapeCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::RemoveShapeAction>(m_shapeId, m_at);
	if (action->doAction())
		manager.append(std::move(action));
}
