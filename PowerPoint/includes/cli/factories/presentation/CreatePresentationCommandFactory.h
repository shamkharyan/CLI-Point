#pragma once

#include "cli/factories/ICommandFactory.h"
#include "viewer/IViewer.h"

#include <string>

namespace ppt::cli::factories
{
	class CreatePresentationCommandFactory : public ICommandFactory
	{
	public:
		CreatePresentationCommandFactory(viewer::IViewer& viewer);
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	private:
		viewer::IViewer& m_viewer;
	};
}
