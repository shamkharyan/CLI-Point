#include "core/actions/slide/RemoveSlideAction.h"
#include "core/actions/slide/AddSlideAction.h"

using namespace ppt::core::act;

RemoveSlideAction::RemoveSlideAction(
	model::Presentation& presentation,
	std::size_t index) :
	m_presentation(presentation),
	m_index(index)
{
}

std::unique_ptr<IAction> RemoveSlideAction::doAction()
{
	auto it = m_presentation.begin() + m_index;
	auto pSlide = m_presentation.removeSlide(it);
	return std::make_unique<AddSlideAction>(m_presentation, pSlide, m_index);
}