#pragma once

#include "cli/commands/ICommand.h"

namespace ppt::cli::cmds
{
	class PrevSlideCommand : public ICommand
	{
	public:
		PrevSlideCommand() = default;
		void execute() override;
	};
}