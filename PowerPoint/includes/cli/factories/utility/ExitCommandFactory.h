#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"

namespace ppt::cli::factories
{
	class ExitCommandFactory : public ICommandFactory
	{
	public:
		ExitCommandFactory(CLIController& controller, CLIViewer& viewer);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		CLIController& m_controller;
		CLIViewer& m_viewer;
	};
}
