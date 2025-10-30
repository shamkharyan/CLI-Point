#pragma once

#include "core/actions/AAction.h"
#include "model/utils/Color.h"
#include "model/Slide.h"
#include "model/utils/Color.h"

#include <optional>
#include <memory>

namespace ppt::core::act
{
	class RemoveSlideAction : public AAction
	{
	public:
		RemoveSlideAction(std::optional<std::size_t> at);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<model::Slide> m_oldSlide;
		std::optional<std::size_t> m_at;
	};
}
