#include "core/actions/EditSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "core/errors/EmptyPresentationException.h"
#include "model/PPModel.h"
#include "model/Slide.h"

#include <cassert>

using namespace ppt::core;

act::EditSlideAction::EditSlideAction(std::optional<std::size_t> at, std::optional <model::utils::Color> bgColor) :
	m_at(at),
	m_bgColor(bgColor)
{
}

bool act::EditSlideAction::doAction()
{
	if (m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (!presentation)
		throw err::MissingPresentationException();

	if (presentation->empty())
		throw err::EmptyPresentationException();

	if (!m_at)
		m_at = presentation->getSelectedId();
	else if (m_at.value() >= presentation->slidesCount())
		throw std::out_of_range("Index out of bounds");

	if (m_bgColor)
	{
		auto& slide = presentation->getSlide(m_at.value());
		m_OldBgColor = slide.getBackgroundColor();
		slide.setBackgroundColor(m_bgColor.value());
	}

	m_completed = true;
	return true;
}

bool act::EditSlideAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	assert(m_at.has_value());
	if (m_OldBgColor)
	{
		auto& slide = presentation->getSlide(m_at.value());
		slide.setBackgroundColor(m_OldBgColor.value());
		m_OldBgColor = std::nullopt;
	}

	m_completed = false;
	return true;
}