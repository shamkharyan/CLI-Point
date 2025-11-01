#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class AddSlideCommand : public ICommand
	{
	public:
		AddSlideCommand(std::optional<std::size_t> at, std::optional<model::utils::Color> color, bool go);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
		std::optional<model::utils::Color> m_color;
		bool m_goto;
	};
}
