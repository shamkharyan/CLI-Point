#pragma once

#include "cli/CommandRegistry.h"
#include "core/IController.h"
#include "viewer/cli/CLIViewer.h"

namespace ppt::cli
{
	class CLIController : public core::IController
	{
	public:
		CLIController(viewer::cli::CLIViewer& viewer, CommandRegistry& registry, model::Presentation& presentation);
		int run() override;
		void exit() override;
	private:
		viewer::cli::CLIViewer& m_viewer;
		CommandRegistry& m_registry;
		model::Presentation& m_presentation;
		bool m_exit = false;
	};
}