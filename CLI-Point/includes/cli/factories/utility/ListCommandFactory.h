//#pragma once
//
//#include "cli/factories/ICommandFactory.h"
//#include "cli/commands/ICommand.h"
//#include "viewer/cli/CLIViewer.h"
//
//namespace ppt::cli::factories
//{
//	class ListCommandFactory : public ICommandFactory
//	{
//	public:
//		ListCommandFactory(viewer::cli::CLIViewer& viewer);
//		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
//	private:
//		viewer::cli::CLIViewer& m_viewer;
//	};
//}
