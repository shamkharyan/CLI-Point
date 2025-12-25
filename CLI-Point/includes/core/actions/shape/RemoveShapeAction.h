#pragma once

#include "core/actions/IAction.h"
#include "model/SlideLayer.h"
#include "model/ShapeData.h"

namespace ppt::core::act
{
	class RemoveShapeAction : public IAction
	{
	public:
		RemoveShapeAction(
			std::shared_ptr<model::SlideLayer> pSlide,
			std::size_t index);

		std::unique_ptr<IAction> doAction() override;

	private:
		std::shared_ptr<model::SlideLayer> m_pSlideLayer;
		std::size_t m_index;
	};
}