#pragma once

#include "cli/commands/ICommand.h"
#include "viewer/IViewer.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class ClearSlideCommand : public ICommand
	{
	public:
		ClearSlideCommand(std::optional<std::size_t> at);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
	};
}
