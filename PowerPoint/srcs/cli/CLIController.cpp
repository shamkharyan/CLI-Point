#include "cli/CLIController.h"
#include "cli/CommandRegistry.h"
#include "cli/factories/AddSlideCommandFactory.h"
#include "cli/factories/CreatePresentationCommandFactory.h"
#include "cli/factories/EditPresentationCommandFactory.h"
#include "cli/factories/ExitCommandFactory.h"
#include "cli/factories/RemoveSlideCommandFactory.h"
#include "cli/factories/UndoCommandFactory.h"
#include "cli/factories/RedoCommandFactory.h"
#include "cli/factories/ListCommandFactory.h"
#include "cli/factories/NextCommandFactory.h"
#include "cli/factories/PrevCommandFactory.h"
#include "cli/Parser.h"
#include "model/PPModel.h"
#include "viewer/cli/CLIViewer.h"

#include <iostream>

using namespace ppt::cli;
using namespace ppt::core;

CLIController::CLIController(viewer::cli::CLIViewer& viewer) : m_viewer(viewer) { registerCommands(); }

void CLIController::run()
{
	auto& context = model::PPModel::instance().getContext();
	m_viewer.showWelcome();

	Parser parser(m_viewer.getIStream());

	while (!m_exit)
	{
		m_viewer.showPrompt(context.getPresentation());
		try
		{
			std::unique_ptr<cmds::ICommand> cmd = parser.parse();
			if (cmd)
				cmd->execute();
		}
		catch (const std::exception& e)
		{
			m_viewer.showError(e.what());
			m_viewer.resetStream();
		}
	}
}

void CLIController::exit() { m_exit = true; }

void CLIController::registerCommands()
{
	auto& registry = CommandRegistry::instance();

	registry.registerFactory("create-presentation", std::make_shared<factories::CreatePresentationCommandFactory>(m_viewer));
	registry.registerFactory("edit-presentation", std::make_shared<factories::EditPresentationCommandFactory>());
	registry.registerFactory("exit", std::make_shared<factories::ExitCommandFactory>(*this, m_viewer));
	registry.registerFactory("add-slide", std::make_shared<factories::AddSlideCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
	registry.registerFactory("undo", std::make_shared<factories::UndoCommandFactory>());
	registry.registerFactory("redo", std::make_shared<factories::RedoCommandFactory>());
	registry.registerFactory("list", std::make_shared<factories::ListCommandFactory>(m_viewer));
	registry.registerFactory("next", std::make_shared<factories::NextCommandFactory>());
	registry.registerFactory("prev", std::make_shared<factories::PrevCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
}