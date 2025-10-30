#pragma once

#include "cli/commands/ICommand.h"

namespace ppt::cli::cmds
{
	class PrevCommand : public ICommand
	{
	public:
		PrevCommand() = default;
		void execute() override;
	};
}