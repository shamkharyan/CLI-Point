#include "core/actions/slide/AddLayerAction.h"
#include "core/actions/slide/RemoveLayerAction.h"

using namespace ppt::core::act;

AddLayerAction::AddLayerAction(
	std::shared_ptr<ppt::model::SlideLayer> pLayer,
	std::shared_ptr<ppt::model::Slide> pSlide,
	std::size_t index) :
	m_pLayer(std::move(pLayer)),
	m_pSlide(std::move(pSlide)),
	m_index(index)
{
}

std::unique_ptr<IAction> AddLayerAction::doAction()
{
	m_pSlide->insertLayer(m_pSlide->begin() + m_index, m_pLayer);
	return std::make_unique<RemoveLayerAction>(m_pSlide, m_index);
}