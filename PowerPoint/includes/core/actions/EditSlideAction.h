#pragma once

#include "core/actions/AAction.h"
#include "model/utils/Color.h"

#include <optional>

namespace ppt::core::act
{
	class EditSlideAction : public AAction
	{
	public:
		EditSlideAction(std::optional<std::size_t> at, std::optional<model::utils::Color> bgColor);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::size_t> m_at;
		std::optional<model::utils::Color> m_bgColor;
		std::optional<model::utils::Color> m_OldBgColor;
	};
}
