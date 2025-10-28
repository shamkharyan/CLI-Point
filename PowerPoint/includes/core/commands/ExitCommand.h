#pragma once

#include "core/commands/ICommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

namespace ppt::core::cmds
{
	class ExitCommand : public ICommand
	{
	public:
		ExitCommand(viewer::IViewer& viewer, bool force);
		void execute() override;
	private:
		viewer::IViewer& m_viewer;
		bool m_force;
	};
}