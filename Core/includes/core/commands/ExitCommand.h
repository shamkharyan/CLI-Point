#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/AConfirmCommand.h"

namespace ppt::core::cmds
{
	class ExitCommand : public AConfirmCommand
	{
	public:
		ExitCommand(model::AppContext& context, viewer::IViewer& viewer, bool force);
		void execute() override;
	private:
		bool m_force;
	};
}