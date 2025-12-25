#include "core/actions/shape/AddShapeAction.h"
#include "core/actions/shape/RemoveShapeAction.h"

using namespace ppt::core::act;

AddShapeAction::AddShapeAction(
	std::shared_ptr<ppt::model::SlideLayer> pSlideLayer,
	std::shared_ptr<ppt::model::ShapeData> pShapeData,
	std::size_t index) :
	m_pSlideLayer(pSlideLayer),
	m_pShapeData(pShapeData),
	m_index(index)
{
}

std::unique_ptr<IAction> AddShapeAction::doAction()
{
	m_pSlideLayer->insertShape(m_pSlideLayer->begin() + m_index, m_pShapeData);
	auto undoAction = std::make_unique<RemoveShapeAction>(m_pSlideLayer, m_index);
	return undoAction;
}

