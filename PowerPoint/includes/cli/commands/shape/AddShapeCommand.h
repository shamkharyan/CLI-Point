#pragma once

#include "cli/commands/ICommand.h"
#include "core/actions/utils/AddShapeParams.h"

namespace ppt::cli::cmds
{
	class AddShapeCommand : public ICommand
	{
	public:
		AddShapeCommand(const core::act::utils::AddShapeParams& params);
		void execute() override;

	private:
		core::act::utils::AddShapeParams m_params;
	};
}
