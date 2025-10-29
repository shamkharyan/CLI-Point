#pragma once

#include "viewer/IViewer.h"
#include "core/commands/ACommand.h"

namespace ppt::core::cmds
{
	class AConfirmCommand : public ACommand
	{
	public:
		AConfirmCommand(model::AppContext& context, viewer::IViewer& viewer) : ACommand(context), m_viewer(viewer) {}
		virtual ~AConfirmCommand() = default;
	protected:
		viewer::IViewer& m_viewer;
	};
}
