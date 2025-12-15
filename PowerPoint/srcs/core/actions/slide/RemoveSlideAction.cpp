//#include "core/actions/slide/RemoveSlideAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//
//#include <cassert>
//
//using namespace ppt::core;
//
//act::RemoveSlideAction::RemoveSlideAction(std::optional<std::size_t> at) : m_at(at) {}
//
//bool act::RemoveSlideAction::doAction()
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
//	m_oldPos = presentation->getSelectedId();
//	m_oldSlide = presentation->getSlide(m_at.value());
//	presentation->removeSlide(m_at.value());
//
//	m_completed = true;
//	return true;
//}
//
//bool act::RemoveSlideAction::undoAction()
//{
//	if (!m_completed)
//		return false;
//
//	auto& context = model::PPModel::instance().getContext();
//	auto presentation = context.getPresentation();
//
//	assert(m_at.has_value());
//	assert(m_oldSlide.has_value());
//	assert(m_oldPos.has_value());
//	presentation->addSlide(m_oldSlide.value(), m_at.value());
//	presentation->setSelectedId(m_oldPos.value());
//
//	m_completed = false;
//	return true;
//}