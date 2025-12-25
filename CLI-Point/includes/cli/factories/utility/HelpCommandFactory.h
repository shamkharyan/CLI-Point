#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "cli/CLIViewer.h"
#include "cli/meta/CommandRegistry.h"

namespace ppt::cli::factories
{
	class HelpCommandFactory : public ICommandFactory
	{
	public:
		HelpCommandFactory(CommandRegistry& registry, CLIViewer& viewer);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		CommandRegistry& m_registry;
		CLIViewer& m_viewer;
	};
}