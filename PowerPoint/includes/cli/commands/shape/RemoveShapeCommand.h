#pragma once

#include "cli/commands/ICommand.h"

#include <optional>

namespace ppt::cli::cmds
{
	class RemoveShapeCommand : public ICommand
	{
	public:
		RemoveShapeCommand(std::size_t shapeId, std::optional<std::size_t> at);
		void execute() override;

	private:
		std::size_t m_shapeId;
		std::optional<std::size_t> m_at;
	};
}
