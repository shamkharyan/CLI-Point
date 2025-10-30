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
		CLIController(viewer::cli::CLIViewer& viewer);
		void run() override;
		void exit() override;
	private:
		void registerCommands();
	private:
		viewer::cli::CLIViewer& m_viewer;
		bool m_exit = false;
	};
}