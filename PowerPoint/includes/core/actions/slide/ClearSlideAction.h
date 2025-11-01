#pragma once

#include "core/actions/AAction.h"
#include "model/Slide.h"

#include <optional>

namespace ppt::core::act
{
	class ClearSlideAction : public AAction
	{
	public:
		ClearSlideAction(std::optional<std::size_t> at);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::size_t> m_at;

		std::optional<model::Slide> m_oldSlide;
	};
}
