#pragma once

#include "cli/commands/ICommand.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "model/Presentation.h"

namespace ppt::cli::cmds
{
	class ExitCommand : public ICommand
	{
	public:
		ExitCommand(
			CLIController& controller, 
			CLIViewer& viewer, 
			model::Presentation& presentation, 
			bool force
		);
		void execute() override;
	private:
		CLIViewer& m_viewer;
		CLIController& m_controller;
		model::Presentation& m_presentation;
		bool m_force;
	};
}