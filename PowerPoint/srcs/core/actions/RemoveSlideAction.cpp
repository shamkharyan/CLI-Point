#include "core/actions/RemoveSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "model/PPModel.h"

#include <cassert>

using namespace ppt::core;

void act::RemoveSlideAction::doAction()
{
	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();
	if (!presentation)
		throw err::MissingPresentationException();
	std::size_t count = presentation->slidesCount();
	if (!count)
		throw std::runtime_error("Empty presentation");
	if (m_at.value_or(count - 1) < count)
	{
		if (!m_at)
			m_at = count - 1;
		m_oldSlide = presentation->getSlide(m_at.value());
		presentation->removeSlide(m_at.value());
	}
	else
		throw std::out_of_range("Index out of range");
}

void act::RemoveSlideAction::undoAction()
{
	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	assert(m_at.has_value());
	assert(m_oldSlide.has_value());
	presentation->addSlide(m_oldSlide.value(), m_at.value());
}