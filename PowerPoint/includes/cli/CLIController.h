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
		static CLIController& instance(model::PPModel& model, viewer::cli::CLIViewer& viewer);
		void run() override;
	private:
		CLIController(model::PPModel& model, viewer::cli::CLIViewer& viewer);
		CLIController(const CLIController&) = delete;
		CLIController(CLIController&&) noexcept = delete;
		CLIController& operator=(const CLIController&) = delete;
		CLIController& operator=(CLIController&&) noexcept = delete;

		void registerMainCommands();
	private:
		model::PPModel & m_model;
		viewer::cli::CLIViewer& m_viewer;
	};
}