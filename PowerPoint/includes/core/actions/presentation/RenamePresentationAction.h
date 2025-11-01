#pragma once

#include "core/actions/AAction.h"

#include <string>
#include <optional>

namespace ppt::core::act
{
	class RenamePresentationAction : public AAction
	{
	public:
		RenamePresentationAction(const std::optional<std::string>& name);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::string> m_oldName;
		std::optional<std::string> m_name;
	};
}
