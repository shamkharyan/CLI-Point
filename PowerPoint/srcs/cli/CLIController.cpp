#include "cli/CLIController.h"
#include "cli/CommandRegistry.h"
#include "cli/factories/AddSlideCommandFactory.h"
#include "cli/factories/CreatePresentationCommandFactory.h"
#include "cli/factories/ExitCommandFactory.h"
#include "cli/factories/RemoveSlideCommandFactory.h"
#include "cli/factories/RemovePresentationCommandFactory.h"
#include "cli/Parser.h"
#include "model/PPModel.h"
#include "viewer/cli/CLIViewer.h"

#include <iostream>

using namespace ppt::cli;
using namespace ppt::core;

CLIController::CLIController(model::PPModel& model, viewer::cli::CLIViewer& viewer) : 
	m_model(model),
	m_viewer(viewer)
{
	registerMainCommands();
}

CLIController& CLIController::instance(model::PPModel& model, viewer::cli::CLIViewer& viewer)
{
	static CLIController obj(model, viewer);
	return obj;
}

void CLIController::run()
{
	m_viewer.showText("PowerPoint CLI v0.1");
	auto& context = m_model.getContext();

	Parser parser(m_viewer.getIStream());

	while (!context.exit)
	{
		auto presentationName = (context.presentation) ? context.presentation->getName() : "";
		m_viewer.showPrompt(presentationName);
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

void CLIController::registerMainCommands()
{
	auto& registry = CommandRegistry::instance();
	auto& context = m_model.getContext();

	registry.registerFactory("create-presentation", std::make_shared<factories::CreatePresentationCommandFactory>(m_viewer));
	registry.registerFactory("remove-presentation", std::make_shared<factories::RemovePresentationCommandFactory>(m_viewer));
	registry.registerFactory("exit", std::make_shared<factories::ExitCommandFactory>(m_viewer));
	registry.registerFactory("add-slide", std::make_shared<factories::AddSlideCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
}