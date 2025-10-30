#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/UndoCommand.h"
#include "cli/errors/InvalidArgumentException.h"

namespace ppt::cli::factories
{
	class UndoCommandFactory : public ICommandFactory
	{
	public:
		UndoCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override
		{
			if (!args.empty())
				throw err::InvalidArgumentException(args.begin()->first);
			return std::make_unique<cmds::UndoCommand>();
		}
	};
}
