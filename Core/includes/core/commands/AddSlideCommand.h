#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/ACommand.h"

#include <string>
#include <optional>

namespace ppt::core::cmds
{
	class AddSlideCommand : public ACommand
	{
	public:
		AddSlideCommand(model::AppContext& context, std::optional<std::size_t> at, model::utils::Color bgColor);
		void execute() override;

	private:
		std::optional<std::size_t> m_at;
		model::utils::Color m_bgColor;
	};
}
