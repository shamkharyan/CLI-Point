//#include "core/actions/slide/NextSlideAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//#include "model/Presentation.h"
//
//#include <cassert>
//
//using namespace ppt::core::act;
//
//bool NextSlideAction::doAction()
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
//	auto id = presentation->getSelectedId();
//	if (id.value() == presentation->slidesCount() - 1)
//		return false;
//
//	presentation->setSelectedId(id.value() + 1);
//
//	m_completed = true;
//	return true;
//}
//
//bool NextSlideAction::undoAction()
//{
//	if (!m_completed)
//		return false;
//
//	auto& context = model::PPModel::instance().getContext();
//	auto presentation = context.getPresentation();
//
//	assert(presentation);
//	assert(!presentation->empty());
//
//	auto id = presentation->getSelectedId();
//	assert(id.value() != 0);
//
//	presentation->setSelectedId(id.value() - 1);
//
//	m_completed = false;
//	return true;
//}