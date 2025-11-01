#pragma once

#include "cli/commands/ICommand.h"

#include <string>
#include <optional>

namespace ppt::cli::cmds
{
	class RenamePresentationCommand : public ICommand
	{
	public:
		RenamePresentationCommand(const std::optional<std::string>& name);
		void execute() override;

	private:
		std::optional<std::string> m_name;
	};
}