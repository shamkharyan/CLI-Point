//#include "cli/commands/shape/MoveShapeCommand.h"
//#include "model/PPModel.h"
//#include "viewer/IViewer.h"
//#include "core/ActionManager.h"
//#include "core/actions/shape/MoveShapeAction.h"
//
//#include <stdexcept>
//
//using namespace ppt::core;
//using namespace ppt::cli::cmds;
//using namespace ppt::model;
//
//MoveShapeCommand::MoveShapeCommand(
//	std::size_t shapeId, 
//	model::utils::Coord position,
//	std::optional<std::size_t> at) :
//	m_shapeId(shapeId),
//	m_position(position),
//	m_at(at)
//{}
//
//void MoveShapeCommand::execute()
//{
//	auto& manager = PPModel::instance().getContext().getActionManager();
//	auto action = std::make_unique<act::MoveShapeAction>(m_shapeId, m_position, m_at);
//	if (action->doAction())
//		manager.append(std::move(action));
//}
