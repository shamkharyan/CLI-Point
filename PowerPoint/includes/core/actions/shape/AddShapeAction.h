//#pragma once
//
//#include "core/actions/IAction.h"
//#include "model/Slide.h"
//#include "model/ShapeData.h"
//
//namespace ppt::core::act
//{
//	class AddShapeAction : public IAction
//	{
//	public:
//		AddShapeAction(
//			model::Slide& slide,
//			const model::ShapeData& shapeData,
//			std::size_t zIndex);
//
//		std::unique_ptr<IAction> doAction() override;
//
//	private:
//		model::Slide& m_slide;
//		model::ShapeData m_shapeData;
//		std::size_t m_zIndex;
//	};
//}