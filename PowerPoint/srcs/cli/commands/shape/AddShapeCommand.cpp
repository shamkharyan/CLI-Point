//#include "cli/commands/shape/AddShapeCommand.h"
//#include "core/ActionManager.h"
//#include "core/actions/shape/AddShapeAction.h"
//#include "cli/commands/ExecutionError.h"
//#include "model/ShapeData.h"
//
//#include <stdexcept>
//
//using namespace ppt::core;
//using namespace ppt::cli::cmds;
//using namespace ppt::model;
//
//AddShapeCommand::AddShapeCommand(
//	model::Presentation& model,
//	core::ActionManager& actionManager,
//	std::size_t at,
//	model::utils::ShapeType type,
//	const model::utils::GeometryData& geometry,
//	const model::utils::StyleData& style,
//	const std::optional<model::utils::TextData>& text,
//	std::size_t zIndex) :
//	m_model(model),
//	m_actionManager(actionManager),
//	m_at(at),
//	m_type(type),
//	m_geometry(geometry),
//	m_style(style),
//	m_text(text),
//	m_zIndex(zIndex)
//{
//}
//
//void AddShapeCommand::execute()
//{
//	if (m_at >= m_model.slidesCount())
//		throw ExecutionError("Slide index out of bounds");
//
//	auto slide = m_model.getSlide(m_at);
//	if (!slide)
//		throw ExecutionError("Slide not found");
//
//	ShapeData shapeData;
//	shapeData.id = 0;  // Will be assigned by appendShapeToLayer
//	shapeData.type = m_type;
//	shapeData.geometry = m_geometry;
//	shapeData.style = m_style;
//	shapeData.text = m_text;
//
//	auto action = std::make_unique<act::AddShapeAction>(*slide, shapeData, m_zIndex);
//	m_actionManager.doAction(std::move(action));
//}
