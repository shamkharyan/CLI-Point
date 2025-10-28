#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"

namespace ppt::core::cmds
{
	class ACommand
	{
	public:
		ACommand(model::AppContext& context) : m_context(context) {}
		virtual ~ACommand() = default;

		virtual void execute() = 0;
	protected:
		model::AppContext& m_context;
	};
}
