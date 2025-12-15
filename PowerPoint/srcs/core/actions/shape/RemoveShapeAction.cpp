//#include "core/actions/shape/RemoveShapeAction.h"
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
//act::RemoveShapeAction::RemoveShapeAction(
//	std::size_t shapeId,
//	std::optional<std::size_t> at) :
//	m_shapeId(shapeId),
//	m_at(at)
//{
//}
//
//bool act::RemoveShapeAction::doAction()
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
//	m_oldShape = presentation->getShape(m_shapeId, m_at.value());
//	presentation->removeShape(m_shapeId, m_at.value());
//
//	m_completed = true;
//	return true;
//}
//
//bool act::RemoveShapeAction::undoAction()
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
//	assert(m_oldShape.has_value());
//
//	presentation->addShapeWithId(m_oldShape.value(), m_at.value());
//	m_oldShape = std::nullopt;
//
//	m_completed = false;
//	return true;
//}
