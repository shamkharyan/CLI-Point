#include "core/actions/slide/AddSlideAction.h"
#include "core/actions/slide/RemoveSlideAction.h"

using namespace ppt::core::act;

AddSlideAction::AddSlideAction(
	model::Presentation& presentation,
	std::shared_ptr<model::Slide> pSlide,
	std::size_t index) :
	m_presentation(presentation),
	m_pSlide(std::move(pSlide)),
	m_index(index) {}

std::unique_ptr<IAction> AddSlideAction::doAction()
{
	auto it = m_presentation.begin() + m_index;
	m_presentation.insertSlide(it, m_pSlide);

	return std::make_unique<RemoveSlideAction>(m_presentation, m_index);
}