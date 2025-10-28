#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/ACommand.h"

#include <string>

namespace ppt::core::cmds
{
	class RemoveSlideCommand : public ACommand
	{
	public:
		RemoveSlideCommand(model::AppContext& context, std::size_t at);
		void execute() override;

	private:
		std::size_t m_at;
	};
}
