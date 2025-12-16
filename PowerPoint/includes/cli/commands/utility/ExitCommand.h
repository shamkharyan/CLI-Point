#pragma once

#include "cli/commands/ICommand.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"

namespace ppt::cli::cmds
{
	class ExitCommand : public ICommand
	{
	public:
		ExitCommand(CLIController& controller, CLIViewer& viewer, bool force);
		void execute() override;
	private:
		CLIViewer& m_viewer;
		CLIController& m_controller;
		bool m_force;
	};
}