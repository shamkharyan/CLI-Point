#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class SetSlideColorCommand : public ICommand
	{
	public:
		SetSlideColorCommand(std::optional<std::size_t> at, model::utils::Color color);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
		model::utils::Color m_color;
	};
}
