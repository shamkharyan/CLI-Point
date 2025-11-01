#pragma once

#include "cli/commands/ICommand.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class DuplicateSlideCommand : public ICommand
	{
	public:
		DuplicateSlideCommand(std::optional<std::size_t> at, std::optional<std::size_t> to, bool go);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
		std::optional<std::size_t> m_to;
		bool m_goto;
	};
}
