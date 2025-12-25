#pragma once

#include "core/actions/IAction.h"
#include "model/SlideLayer.h"
#include "model/ShapeData.h"

namespace ppt::core::act
{
	class AddShapeAction : public IAction
	{
	public:
		AddShapeAction(
			std::shared_ptr<model::SlideLayer> pSlide,
			std::shared_ptr<model::ShapeData> pShapeData,
			std::size_t index);

		std::unique_ptr<IAction> doAction() override;

	private:
		std::shared_ptr<model::SlideLayer> m_pSlideLayer;
		std::shared_ptr<model::ShapeData> m_pShapeData;
		std::size_t m_index;
	};
}