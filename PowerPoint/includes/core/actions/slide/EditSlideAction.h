#pragma once

#include "core/actions/IAction.h"
#include "model/Slide.h"
#include "model/Presentation.h"
#include "model/utils/Color.h"

namespace ppt::core::act
{
	class EditSlideAction : public IAction
	{
	public:
		EditSlideAction(
			model::Presentation& presentation,
			std::shared_ptr<model::Slide> pSlide,
			std::size_t index,
			model::utils::Color newColor
		);

		std::unique_ptr<IAction> doAction() override;

	private:
		model::Presentation& m_presentation;
		std::shared_ptr<model::Slide> m_pSlide;
		std::size_t m_index;
		model::utils::Color m_newColor;
	};
}