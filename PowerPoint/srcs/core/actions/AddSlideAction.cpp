#include "core/actions/AddSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "model/PPModel.h"
#include "model/Slide.h"

#include <cassert>

using namespace ppt::core;

act::AddSlideAction::AddSlideAction(std::optional<std::size_t> at, model::utils::Color bgColor) :
	m_at(at),
	m_bgColor(bgColor)
{
}

bool act::AddSlideAction::doAction()
{
	if (m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (!presentation)
		throw err::MissingPresentationException();
	std::size_t count = presentation->slidesCount();
	if (m_at.value_or(count) <= count)
		presentation->addSlide(model::Slide(m_bgColor), m_at.value_or(count));
	else
		throw std::out_of_range("Index out of bounds");
	if (!m_at)
		m_at = count;

	m_completed = true;
	return true;
}

bool act::AddSlideAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	assert(m_at.has_value());
	presentation->removeSlide(m_at.value());

	m_completed = false;
	return true;
}