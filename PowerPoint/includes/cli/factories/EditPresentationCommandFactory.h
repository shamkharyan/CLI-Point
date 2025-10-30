#pragma once

#include "cli/factories/ICommandFactory.h"
#include "viewer/IViewer.h"

#include <string>

namespace ppt::cli::factories
{
	class EditPresentationCommandFactory : public ICommandFactory
	{
	public:
		EditPresentationCommandFactory() = default;
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	};
}
