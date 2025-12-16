#pragma once

#include "core/actions/IAction.h"
#include "core/actions/slide/AddSlideAction.h"
#include "model/Slide.h"

#include <optional>

namespace ppt::core::act
{
	class RemoveSlideAction : public IAction
	{
	public:
		RemoveSlideAction(model::Presentation& presentation, std::size_t index);
		std::unique_ptr<IAction> doAction() override;

	private:
		model::Presentation& m_presentation;
		std::size_t m_index;
	};
}
