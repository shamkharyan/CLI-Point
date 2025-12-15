//#include "cli/commands/shape/ResizeShapeCommand.h"
//#include "model/PPModel.h"
//#include "viewer/IViewer.h"
//#include "core/ActionManager.h"
//#include "core/actions/shape/ResizeShapeAction.h"
//
//#include <stdexcept>
//
//using namespace ppt::core;
//using namespace ppt::cli::cmds;
//using namespace ppt::model;
//
//ResizeShapeCommand::ResizeShapeCommand(
//	std::size_t shapeId,
//	model::utils::Coord size,
//	std::optional<std::size_t> at) :
//	m_shapeId(shapeId),
//	m_size(size),
//	m_at(at)
//{
//}
//
//void ResizeShapeCommand::execute()
//{
//	auto& manager = PPModel::instance().getContext().getActionManager();
//	auto action = std::make_unique<act::ResizeShapeAction>(m_shapeId, m_size, m_at);
//	if (action->doAction())
//		manager.append(std::move(action));
//}
