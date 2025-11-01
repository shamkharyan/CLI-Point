#pragma once

#include "cli/commands/ICommand.h"
#include "viewer/IViewer.h"

#include <string>
#include <optional>

namespace ppt::cli::cmds
{
	class CreatePresentationCommand : public ICommand
	{
	public:
		CreatePresentationCommand(viewer::IViewer& viewer, const std::optional<std::string>& name);
		void execute() override;

	private:
		viewer::IViewer& m_viewer;
		std::optional<std::string> m_name;
	};
}