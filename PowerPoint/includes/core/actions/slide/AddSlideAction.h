#pragma once

#include "core/actions/AAction.h"
#include "model/utils/Color.h"

#include <optional>

namespace ppt::core::act
{
	class AddSlideAction : public AAction
	{
	public:
		AddSlideAction(std::optional<std::size_t> at, std::optional<model::utils::Color> color, bool go);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::size_t> m_at;
		std::optional<model::utils::Color> m_color;
		bool m_goto;

		std::optional<std::size_t> m_oldPos = std::nullopt;
	};
}
