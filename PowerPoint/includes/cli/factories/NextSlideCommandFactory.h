#pragma once

#include "cli/factories/ICommandFactory.h"

namespace ppt::cli::factories
{
	class NextSlideCommandFactory : public ICommandFactory
	{
	public:
		NextSlideCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
