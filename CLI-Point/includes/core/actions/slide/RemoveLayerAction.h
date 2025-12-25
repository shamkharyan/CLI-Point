#pragma once

#include "core/actions/IAction.h"
#include "model/Slide.h"
#include "model/Presentation.h"

namespace ppt::core::act
{
	class RemoveLayerAction : public IAction
	{
	public:
		RemoveLayerAction(
			std::shared_ptr<model::Slide> pSlide,
			std::size_t index);

		std::unique_ptr<IAction> doAction() override;

	private:
		std::shared_ptr<model::Slide> m_pSlide;
		std::size_t m_index;
	};
}