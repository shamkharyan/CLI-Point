#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class MoveSlideCommand : public ICommand
	{
	public:
		MoveSlideCommand(std::optional<std::size_t> at, std::size_t to);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
		std::size_t m_to;
	};
}
