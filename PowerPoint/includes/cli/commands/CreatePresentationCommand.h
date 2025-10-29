#pragma once

#include "cli/commands/ICommand.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <string>

namespace ppt::cli::cmds
{
	class CreatePresentationCommand : public ICommand
	{
	public:
		CreatePresentationCommand(viewer::IViewer& viewer, const std::string& name);
		void execute() override;

	private:
		viewer::IViewer& m_viewer;
		std::string m_name;
	};
}