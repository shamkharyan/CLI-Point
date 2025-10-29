#pragma once

#include "cli/CommandRegistry.h"
#include "core/IController.h"
#include "model/AppContext.h"
#include "model/PPModel.h"
#include "viewer/cli/CLIViewer.h"

namespace ppt::cli
{
	class CLIController : public core::IController
	{
	public:
		static CLIController& instance(viewer::cli::CLIViewer& viewer);
		void run() override;
		void exit() override;
	private:
		CLIController(viewer::cli::CLIViewer& viewer);
		CLIController(const CLIController&) = delete;
		CLIController(CLIController&&) noexcept = delete;
		CLIController& operator=(const CLIController&) = delete;
		CLIController& operator=(CLIController&&) noexcept = delete;

		void registerMainCommands();
	private:
		viewer::cli::CLIViewer& m_viewer;
		bool m_exit = false;
	};
}