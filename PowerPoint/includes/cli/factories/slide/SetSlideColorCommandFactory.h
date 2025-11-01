#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"

#include <string>

namespace ppt::cli::factories
{
	class SetSlideColorCommandFactory : public ICommandFactory
	{
	public:
		SetSlideColorCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
