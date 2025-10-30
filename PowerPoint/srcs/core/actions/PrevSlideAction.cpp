#include "core/actions/PrevSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "core/errors/EmptyPresentationException.h"
#include "model/PPModel.h"
#include "model/Presentation.h"

using namespace ppt::core::act;

bool PrevSlideAction::doAction()
{
	if (m_completed)
		return false;

	auto presentation = model::PPModel::instance().getContext().getPresentation();
	if (!presentation)
		throw err::MissingPresentationException();

	auto id = presentation->getSelectedId();
	if (!id)
		throw err::EmptyPresentationException();

	if (id.value() <= 0)
		return false;

	presentation->prevSlide();

	m_completed = true;
	return true;
}

bool PrevSlideAction::undoAction()
{
	if (!m_completed)
		return false;

	auto presentation = model::PPModel::instance().getContext().getPresentation();
	presentation->nextSlide();

	m_completed = false;
	return true;
}