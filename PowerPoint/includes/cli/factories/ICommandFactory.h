#pragma once

#include "cli/commands/ICommand.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace ppt::cli::factories
{
	using Arguments = std::unordered_map<std::string, std::vector<std::string>>;

	class ICommandFactory
	{
	public:
		virtual ~ICommandFactory() = default;
		virtual std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) = 0;
	};
}
