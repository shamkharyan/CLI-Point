#pragma once

#include "cli/commands/ICommand.h"
#include "cli/CLIViewer.h"
#include "cli/meta/CommandRegistry.h"

namespace ppt::cli::cmds
{
	class HelpCommand : public ICommand
	{
	public:
		HelpCommand(CommandRegistry& registry, CLIViewer& viewer, const std::string& specificCommandName);
		void execute() override;
	private:
		CommandRegistry& m_registry;
		CLIViewer& m_viewer;

		std::string m_specificCommandName;
	};
}