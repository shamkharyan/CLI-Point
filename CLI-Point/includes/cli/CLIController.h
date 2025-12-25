#pragma once

#include "cli/meta/CommandRegistry.h"
#include "core/IController.h"
#include "cli/CLIViewer.h"

namespace ppt::cli
{
	class CLIController : public core::IController
	{
	public:
		CLIController(CLIViewer& viewer, CommandRegistry& registry, model::Presentation& presentation);
		int run() override;
		void exit() override;
	private:
		CLIViewer& m_viewer;
		CommandRegistry& m_registry;
		model::Presentation& m_presentation;
		bool m_exit = false;
	};
}