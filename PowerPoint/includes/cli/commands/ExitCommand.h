#pragma once

#include "cli/commands/ICommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/IController.h"

namespace ppt::cli::cmds
{
	class ExitCommand : public ICommand
	{
	public:
		ExitCommand(core::IController& controller, viewer::IViewer& viewer, bool force);
		void execute() override;
	private:
		viewer::IViewer& m_viewer;
		core::IController& m_controller;
		bool m_force;
	};
}