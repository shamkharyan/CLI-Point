#pragma once

#include "cli/commands/ICommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class AddSlideCommand : public ICommand
	{
	public:
		AddSlideCommand(std::optional<std::size_t> at, model::utils::Color bgColor);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
		model::utils::Color m_bgColor;
	};
}
