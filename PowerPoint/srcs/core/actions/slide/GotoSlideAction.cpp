//#include "core/actions/slide/GotoSlideAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//#include "model/Presentation.h"
//
//#include <cassert>
//
//using namespace ppt::core::act;
//
//GotoSlideAction::GotoSlideAction(std::size_t pos) : m_pos(pos) {}
//
//bool GotoSlideAction::doAction()
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
//	if (m_pos >= presentation->slidesCount())
//		throw std::out_of_range("Out of range");
//
//	m_oldPos = presentation->getSelectedId();
//	presentation->setSelectedId(m_pos);
//
//	m_completed = true;
//	return true;
//}
//
//bool GotoSlideAction::undoAction()
//{
//	if (!m_completed)
//		return false;
//
//	auto& context = model::PPModel::instance().getContext();
//	auto presentation = context.getPresentation();
//
//	assert(presentation);
//	assert(!presentation->empty());
//	assert(m_oldPos.has_value());
//	assert(m_oldPos.value() < presentation->slidesCount());
//
//	presentation->setSelectedId(m_oldPos.value());
//	m_oldPos = std::nullopt;
//
//	m_completed = false;
//	return true;
//}