//#include "core/actions/slide/ClearSlideAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//
//#include <cassert>
//
//using namespace ppt::core;
//
//act::ClearSlideAction::ClearSlideAction(std::optional<std::size_t> at) : m_at(at) {}
//
//bool act::ClearSlideAction::doAction()
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
//	else if (m_at.value() >= presentation->slidesCount())
//		throw std::out_of_range("Index out of bounds");
//
//	m_oldSlide = presentation->getSlide(m_at.value());
//	presentation->clearSlide(m_at.value());
//
//	m_completed = true;
//	return true;
//}
//
//bool act::ClearSlideAction::undoAction()
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
//	assert(m_oldSlide.has_value());
//
//	presentation->replaceSlide(m_oldSlide.value(), m_at.value());
//
//	m_completed = false;
//	return true;
//}