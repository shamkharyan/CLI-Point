#pragma once

#include "cli/factories/ICommandFactory.h"

namespace ppt::cli::factories
{
	class RenamePresentationCommandFactory : public ICommandFactory
	{
	public:
		RenamePresentationCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
