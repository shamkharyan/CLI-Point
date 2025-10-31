#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"

#include <string>

namespace ppt::cli::factories
{
	class EditSlideCommandFactory : public ICommandFactory
	{
	public:
		EditSlideCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
