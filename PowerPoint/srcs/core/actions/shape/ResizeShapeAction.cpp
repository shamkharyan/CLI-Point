//#include "core/actions/shape/ResizeShapeAction.h"
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
//act::ResizeShapeAction::ResizeShapeAction(
//	std::size_t shapeId,
//	model::utils::Coord size,
//	std::optional<std::size_t> at) :
//	m_shapeId(shapeId),
//	m_size(size),
//	m_at(at)
//{
//}
//
//bool act::ResizeShapeAction::doAction()
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
//	m_oldSize = presentation->getShape(m_shapeId, m_at.value()).geometry.size;
//	presentation->setShapeSize(m_shapeId, m_size, m_at.value());
//
//	m_completed = true;
//	return true;
//}
//
//bool act::ResizeShapeAction::undoAction()
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
//	assert(m_oldSize.has_value());
//
//	presentation->setShapeSize(m_shapeId, m_oldSize.value(), m_at.value());
//	m_oldSize = std::nullopt;
//
//	m_completed = false;
//	return true;
//}
