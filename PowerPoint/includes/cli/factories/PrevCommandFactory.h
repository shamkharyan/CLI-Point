#pragma once

#include "cli/factories/ICommandFactory.h"

namespace ppt::cli::factories
{
	class PrevCommandFactory : public ICommandFactory
	{
	public:
		PrevCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
