#pragma once

#include "cli/factories/ICommandFactory.h"

namespace ppt::cli::factories
{
	class GotoSlideCommandFactory : public ICommandFactory
	{
	public:
		GotoSlideCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
