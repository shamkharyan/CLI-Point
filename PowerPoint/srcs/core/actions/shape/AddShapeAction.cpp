//#include "core/actions/shape/AddShapeAction.h"
//#include "core/actions/shape/RemoveShapeAction.h"
//
//using namespace ppt::core::act;
//
//AddShapeAction::AddShapeAction(
//	model::Slide& slide,
//	const model::ShapeData& shapeData,
//	std::size_t zIndex) :
//	m_slide(slide),
//	m_shapeData(shapeData),
//	m_zIndex(zIndex)
//{
//}
//
//std::unique_ptr<IAction> AddShapeAction::doAction()
//{
//	m_slide.appendShapeToLayer(m_zIndex, std::move(m_shapeData));
//	auto undoAction = std::make_unique<RemoveShapeAction>(m_slide, m_shapeData.id);
//	return undoAction;
//}
//
