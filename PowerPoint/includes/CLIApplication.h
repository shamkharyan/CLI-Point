#pragma once

#include "cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "cli/meta/CommandRegistry.h"
#include "core/ActionManager.h"

namespace ppt
{
	class CLIApplication
	{
	public:
		static CLIApplication& instance();
		int execute();
	private:
		CLIApplication();
		CLIApplication(const CLIApplication&) = delete;
		CLIApplication(CLIApplication&&) noexcept = delete;
		CLIApplication& operator=(const CLIApplication&) = delete;
		CLIApplication& operator=(CLIApplication&&) noexcept = delete;

		void registerCommands();
	private:
		model::Presentation m_presentation;
		core::ActionManager m_actionManager;
		cli::CLIViewer m_viewer;
		cli::CommandRegistry m_registry;
		cli::CLIController m_controller;
	};
}
