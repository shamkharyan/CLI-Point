#include "core/actions/slide/RemoveLayerAction.h"
#include "core/actions/slide/AddLayerAction.h"

using namespace ppt::core::act;

RemoveLayerAction::RemoveLayerAction(
	std::shared_ptr<ppt::model::Slide> pSlide,
	std::size_t index) :
	m_pSlide(std::move(pSlide)),
	m_index(index)
{
}

std::unique_ptr<IAction> RemoveLayerAction::doAction()
{
	auto pRemovedLayer = m_pSlide->removeLayer(m_pSlide->begin() + m_index);
	return std::make_unique<AddLayerAction>(pRemovedLayer, m_pSlide, m_index);
}