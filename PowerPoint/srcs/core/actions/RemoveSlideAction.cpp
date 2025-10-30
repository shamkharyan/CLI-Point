#include "core/actions/RemoveSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "model/PPModel.h"

#include <cassert>

using namespace ppt::core;

act::RemoveSlideAction::RemoveSlideAction(std::optional<std::size_t> at) : m_at(at) {}

bool act::RemoveSlideAction::doAction()
{
	if (m_completed)
		return false;

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

	m_completed = true;
	return true;
}

bool act::RemoveSlideAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	assert(m_at.has_value());
	assert(m_oldSlide.has_value());
	presentation->addSlide(m_oldSlide.value(), m_at.value());

	m_completed = false;
	return true;
}