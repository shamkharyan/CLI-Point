#pragma once

#include "cli/commands/ICommand.h"

namespace ppt::cli::cmds
{
	class NextSlideCommand : public ICommand
	{
	public:
		NextSlideCommand() = default;
		void execute() override;
	};
}