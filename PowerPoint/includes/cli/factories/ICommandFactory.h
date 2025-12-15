#pragma once

#include "cli/commands/ICommand.h"
#include "cli/parsing/ValidatedRawCommand.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace ppt::cli::factories
{
	class ICommandFactory
	{
	public:
		virtual ~ICommandFactory() = default;
		virtual std::unique_ptr<cmds::ICommand> createCommand(const ValidatedRawCommand& args) = 0;
	};
}
