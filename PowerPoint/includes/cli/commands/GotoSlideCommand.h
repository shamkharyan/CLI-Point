#pragma once

#include "cli/commands/ICommand.h"

#include <cstddef>

namespace ppt::cli::cmds
{
	class GotoSlideCommand : public ICommand
	{
	public:
		GotoSlideCommand(std::size_t at);
		void execute() override;
	private:
		std::size_t m_at;
	};
}