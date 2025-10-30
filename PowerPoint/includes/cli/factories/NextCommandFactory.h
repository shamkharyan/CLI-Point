#pragma once

#include "cli/factories/ICommandFactory.h"

namespace ppt::cli::factories
{
	class NextCommandFactory : public ICommandFactory
	{
	public:
		NextCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
