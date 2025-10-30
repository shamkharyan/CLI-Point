#pragma once

#include "cli/factories/ICommandFactory.h"

#include <string>

namespace ppt::cli::factories
{
	class RemoveSlideCommandFactory : public ICommandFactory
	{
	public:
		RemoveSlideCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
