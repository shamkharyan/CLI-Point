#pragma once

#include "core/actions/IAction.h"
#include "model/Slide.h"
#include "model/Presentation.h"

namespace ppt::core::act
{
	class AddLayerAction : public IAction
	{
	public:
		AddLayerAction(
			std::shared_ptr<model::SlideLayer> pLayer,
			std::shared_ptr<model::Slide> pSlide,
			std::size_t index);

		std::unique_ptr<IAction> doAction() override;

	private:
		std::shared_ptr<model::SlideLayer> m_pLayer;
		std::shared_ptr<model::Slide> m_pSlide;
		std::size_t m_index;
	};
}