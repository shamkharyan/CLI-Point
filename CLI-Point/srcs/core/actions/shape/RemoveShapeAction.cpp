#include "core/actions/shape/AddShapeAction.h"
#include "core/actions/shape/RemoveShapeAction.h"

using namespace ppt::core::act;

RemoveShapeAction::RemoveShapeAction(
	std::shared_ptr<ppt::model::SlideLayer> pSlideLayer,
	std::size_t index) :
	m_pSlideLayer(pSlideLayer),
	m_index(index)
{
}

std::unique_ptr<IAction> RemoveShapeAction::doAction()
{
	auto pRemovedShape = m_pSlideLayer->removeShape(m_pSlideLayer->begin() + m_index);
	auto undoAction = std::make_unique<AddShapeAction>(m_pSlideLayer, pRemovedShape, m_index);
	return undoAction;
}
