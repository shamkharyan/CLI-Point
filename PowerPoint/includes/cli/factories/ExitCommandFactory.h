#pragma once

#include "cli/factories/ICommandFactory.h"
#include "viewer/IViewer.h"
#include "core/IController.h"

namespace ppt::cli::factories
{
	class ExitCommandFactory : public ICommandFactory
	{
	public:
		ExitCommandFactory(core::IController& controller, viewer::IViewer& viewer);
		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
	private:
		core::IController& m_controller;
		viewer::IViewer& m_viewer;
	};
}
