#include "core/actions/NextSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "core/errors/EmptyPresentationException.h"
#include "model/PPModel.h"
#include "model/Presentation.h"

using namespace ppt::core::act;

bool NextSlideAction::doAction()
{
	if (m_completed)
		return false;

	auto presentation = model::PPModel::instance().getContext().getPresentation();
	if (!presentation)
		throw err::MissingPresentationException();

	auto id = presentation->getSelectedId();
	if (!id)
		throw err::EmptyPresentationException();

	if (id.value() >= presentation->slidesCount() - 1)
		return false;

	presentation->nextSlide();

	m_completed = true;
	return true;
}

bool NextSlideAction::undoAction()
{
	if (!m_completed)
		return false;

	auto presentation = model::PPModel::instance().getContext().getPresentation();
	presentation->prevSlide();

	m_completed = false;
	return true;
}