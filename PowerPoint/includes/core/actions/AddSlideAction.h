#pragma once

#include "core/actions/AAction.h"
#include "model/utils/Color.h"

#include <optional>

namespace ppt::core::act
{
	class AddSlideAction : public AAction
	{
	public:
		AddSlideAction(std::optional<std::size_t> at, model::utils::Color bgColor);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::size_t> m_at;
		model::utils::Color m_bgColor;
	};
}
