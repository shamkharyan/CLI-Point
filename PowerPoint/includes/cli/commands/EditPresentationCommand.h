#pragma once

#include "cli/commands/ICommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <string>

namespace ppt::cli::cmds
{
	class EditPresentationCommand : public ICommand
	{
	public:
		EditPresentationCommand(const std::optional<std::string>& name) : m_name(name) {}
		void execute() override;

	private:
		std::optional<std::string> m_name;
	};
}