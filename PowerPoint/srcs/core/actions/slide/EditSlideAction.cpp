#include "core/actions/slide/EditSlideAction.h"

using namespace ppt::core::act;

EditSlideAction::EditSlideAction(
	model::Presentation& presentation,
	std::shared_ptr<model::Slide> pSlide,
	std::size_t index,
	model::utils::Color newColor) :
	m_presentation(presentation),
	m_pSlide(pSlide),
	m_index(index),
	m_newColor(newColor)
{
}

std::unique_ptr<IAction> EditSlideAction::doAction()
{
	auto oldColor = m_pSlide->getColor();
	m_pSlide->setColor(m_newColor);
	return std::make_unique<EditSlideAction>(m_presentation, m_pSlide, m_index, oldColor);
}