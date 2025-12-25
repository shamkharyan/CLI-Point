#pragma once

#include "core/actions/IAction.h"
#include "model/Slide.h"
#include "model/Presentation.h"

namespace ppt::core::act
{
	class AddSlideAction : public IAction
	{
	public:
		AddSlideAction(
			model::Presentation& presentation,
			std::shared_ptr<model::Slide> pSlide,
			std::size_t index);

		std::unique_ptr<IAction> doAction() override;

	private:
		model::Presentation& m_presentation;
		std::shared_ptr<model::Slide> m_pSlide;
		std::size_t m_index;
	};
}