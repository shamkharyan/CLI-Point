#pragma once

#include "core/actions/AAction.h"

#include <optional>

namespace ppt::core::act
{
	class DuplicateSlideAction : public AAction
	{
	public:
		DuplicateSlideAction(std::optional<std::size_t> at, std::optional<std::size_t> to, bool go);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::size_t> m_at;
		std::optional<std::size_t> m_to;
		bool m_goto;

		std::optional<std::size_t> m_oldPos;
	};
}
