#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/ICommand.h"

#include <string>
#include <optional>

namespace ppt::core::cmds
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
