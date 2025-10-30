#pragma once

#include "cli/commands/ICommand.h"

namespace ppt::cli::cmds
{
	class NextCommand : public ICommand
	{
	public:
		NextCommand() = default;
		void execute() override;
	};
}