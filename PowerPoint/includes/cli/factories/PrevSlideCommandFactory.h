#pragma once

#include "cli/factories/ICommandFactory.h"

namespace ppt::cli::factories
{
	class PrevSlideCommandFactory : public ICommandFactory
	{
	public:
		PrevSlideCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
