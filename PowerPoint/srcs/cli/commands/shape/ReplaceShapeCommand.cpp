//#include "cli/commands/shape/ReplaceShapeCommand.h"
//#include "model/PPModel.h"
//#include "viewer/IViewer.h"
//#include "core/ActionManager.h"
//#include "core/actions/shape/ReplaceShapeAction.h"
//
//#include <stdexcept>
//
//using namespace ppt::core;
//using namespace ppt::cli::cmds;
//using namespace ppt::model;
//
//ReplaceShapeCommand::ReplaceShapeCommand(
//	std::size_t shapeId,
//	model::utils::ShapeType type,
//	std::optional<std::size_t> at) :
//	m_shapeId(shapeId),
//	m_type(type),
//	m_at(at)
//{
//}
//
//void ReplaceShapeCommand::execute()
//{
//	auto& manager = PPModel::instance().getContext().getActionManager();
//	auto action = std::make_unique<act::ReplaceShapeAction>(m_shapeId, m_type, m_at);
//	if (action->doAction())
//		manager.append(std::move(action));
//}
