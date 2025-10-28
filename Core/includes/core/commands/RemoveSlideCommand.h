#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/ICommand.h"

#include <string>

namespace ppt::core::cmds
{
	class RemoveSlideCommand : public ICommand
	{
	public:
		RemoveSlideCommand(std::size_t at);
		void execute() override;

	private:
		std::size_t m_at;
	};
}
