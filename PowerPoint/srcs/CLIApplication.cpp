#include "CLIApplication.h"

#include "cli/CommandRegistry.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "cli/meta/CommandMeta.h"
#include "cli/meta/ArgumentMeta.h"

#include "cli/parsing/BoolFactory.h"

#include "cli/factories/utility/ExitCommandFactory.h"

#include <iostream>

using namespace ppt;
using namespace ppt::cli;

CLIApplication& CLIApplication::instance()
{
	static CLIApplication app;
	return app;
}

int CLIApplication::execute()
{
	return m_controller.run();
}

CLIApplication::CLIApplication() : 
	m_viewer(std::cin, std::cout),
	m_presentation("Untitled"),
	m_controller(m_viewer, m_registry, m_presentation)
{
	registerCommands();
}

void CLIApplication::registerCommands()
{
	meta::CommandMeta exitCmdMeta(
		"exit",
		"Exit the application",
		std::make_shared<factories::ExitCommandFactory>(m_controller, m_viewer)
	);

	meta::ArgumentMeta forceArgMeta(
		"force",
		"Force exit without confirmation",
		false,
		false
	);

	forceArgMeta.registerNameAlias("-f");
	forceArgMeta.registerNameAlias("--force");

	forceArgMeta.registerArgValueFactory(std::make_unique<cli::BoolFactory>());

	exitCmdMeta.registerArgumentMeta(std::move(forceArgMeta));

	m_registry.registerCommandMeta(std::move(exitCmdMeta));
}