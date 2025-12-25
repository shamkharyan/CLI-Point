#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "model/Presentation.h"

namespace ppt::cli::factories
{
	class ExitCommandFactory : public ICommandFactory
	{
	public:
		ExitCommandFactory(
			CLIController& controller, 
			CLIViewer& viewer, 
			model::Presentation& m_presentation
		);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		CLIController& m_controller;
		CLIViewer& m_viewer;
		model::Presentation& m_presentation;
	};
}
