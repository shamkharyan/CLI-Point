//#include "core/actions/shape/ReplaceShapeAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//#include "model/Slide.h"
//#include "model/Shape.h"
//
//#include <cassert>
//
//using namespace ppt::core;
//
//act::ReplaceShapeAction::ReplaceShapeAction(
//	std::size_t shapeId,
//	model::utils::ShapeType type,
//	std::optional<std::size_t> at) :
//	m_shapeId(shapeId),
//	m_type(type),
//	m_at(at)
//{
//}
//
//bool act::ReplaceShapeAction::doAction()
//{
//	if (m_completed)
//		return false;
//
//	auto& context = model::PPModel::instance().getContext();
//	auto presentation = context.getPresentation();
//
//	if (!presentation)
//		throw err::MissingPresentationException();
//
//	if (presentation->empty())
//		throw err::EmptyPresentationException();
//
//	if (!m_at)
//		m_at = presentation->getSelectedId();
//
//	if (m_at.value() >= presentation->slidesCount())
//		throw std::out_of_range("Index out of range");
//
//	if (!presentation->isShapeExists(m_shapeId, m_at.value()))
//		throw std::out_of_range("Shape with given index don't exists");
//
//	m_oldType = presentation->getShape(m_shapeId, m_at.value()).type;
//	presentation->setShapeType(m_shapeId, m_type, m_at.value());
//
//	m_completed = true;
//	return true;
//}
//
//bool act::ReplaceShapeAction::undoAction()
//{
//	if (!m_completed)
//		return false;
//
//	auto& context = model::PPModel::instance().getContext();
//	auto presentation = context.getPresentation();
//
//	assert(presentation);
//	assert(!presentation->empty());
//	assert(m_at.has_value());
//	assert(m_oldType.has_value());
//
//	presentation->setShapeType(m_shapeId, m_oldType.value(), m_at.value());
//	m_oldType = std::nullopt;
//
//	m_completed = false;
//	return true;
//}
