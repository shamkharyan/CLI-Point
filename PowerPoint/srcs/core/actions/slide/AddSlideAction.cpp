#include "core/actions/slide/AddSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "model/PPModel.h"
#include "model/Slide.h"

#include <cassert>

using namespace ppt::core;

act::AddSlideAction::AddSlideAction(
	std::optional<std::size_t> at, 
	std::optional<model::utils::Color> color,
	bool go) :
	m_at(at),
	m_color(color),
	m_goto(go)
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

	auto count = presentation->slidesCount();

	if (!m_at)
		m_at = count;

	if (m_at.value() > count)
		throw std::out_of_range("Index out of range");

	if (!m_color)
		m_color = model::utils::Color{ 255,255,255 };

	if (m_goto)
		m_oldPos = presentation->getSelectedId();

	// Can change selectedId
	presentation->addSlide(model::Slide(m_color.value()), m_at.value());

	if (m_goto)
		presentation->setSelectedId(m_at.value());

	m_completed = true;
	return true;
}

bool act::AddSlideAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	assert(presentation);

	auto count = presentation->slidesCount();
	assert(m_at.has_value());
	assert(m_at.value() < count);

	presentation->removeSlide(m_at.value());

	if (m_goto)
	{
		assert(m_oldPos.has_value());
		assert(m_oldPos.value() < count);
		presentation->setSelectedId(m_oldPos.value());
		m_oldPos = std::nullopt;
	}

	m_completed = false;
	return true;
}
