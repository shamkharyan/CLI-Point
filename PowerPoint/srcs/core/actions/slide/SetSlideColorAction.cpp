//#include "core/actions/slide/SetSlideColorAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//#include "model/Slide.h"
//
//#include <cassert>
//
//using namespace ppt::core;
//
//act::SetSlideColorAction::SetSlideColorAction(std::optional<std::size_t> at, model::utils::Color color) :
//	m_at(at),
//	m_color(color)
//{
//}
//
//bool act::SetSlideColorAction::doAction()
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
//	else if (m_at.value() >= presentation->slidesCount())
//		throw std::out_of_range("Index out of bounds");
//
//	m_OldColor = presentation->getSlideColor(m_at.value());
//	presentation->setSlideColor(m_color, m_at.value());
//
//	m_completed = true;
//	return true;
//}
//
//bool act::SetSlideColorAction::undoAction()
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
//	assert(m_OldColor.has_value());
//
//	presentation->setSlideColor(m_OldColor.value(), m_at.value());
//
//	m_completed = false;
//	return true;
//}