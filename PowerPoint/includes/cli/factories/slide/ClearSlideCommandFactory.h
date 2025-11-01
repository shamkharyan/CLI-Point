#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"

namespace ppt::cli::factories
{
	class ClearSlideCommandFactory : public ICommandFactory
	{
	public:
		ClearSlideCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
