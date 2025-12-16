#include "CLIApplication.h"

#include "cli/meta/CommandRegistry.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "cli/meta/CommandMeta.h"
#include "cli/meta/ArgumentMeta.h"

#include "cli/parsing/factories/BoolFactory.h"
#include "cli/parsing/factories/SizeTFactory.h"
#include "cli/parsing/factories/ColorNameFactory.h"
#include "cli/parsing/factories/ColorRGBFactory.h"
#include "cli/parsing/factories/ColorRGBAFactory.h"
#include "cli/parsing/factories/StringFactory.h"

#include "cli/factories/utility/ExitCommandFactory.h"
#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/factories/slide/RemoveSlideCommandFactory.h"
#include "cli/factories/slide/EditSlideCommandFactory.h"
#include "cli/factories/slide/DuplicateSlideCommandFactory.h"
#include "cli/factories/slide/MoveSlideCommandFactory.h"
#include "cli/factories/utility/UndoCommandFactory.h"
#include "cli/factories/utility/RedoCommandFactory.h"
#include "cli/factories/utility/HelpCommandFactory.h"

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
	m_presentation("Untitled"),
	m_viewer(m_presentation, std::cin, std::cout),
	m_controller(m_viewer, m_registry, m_presentation)
{
	registerCommands();
}

void CLIApplication::registerCommands()
{
	// exit Command
	{
		meta::CommandMeta exitMeta(
			"exit",
			"Exit the application",
			std::make_shared<factories::ExitCommandFactory>(m_controller, m_viewer)
		);

		// force argument
		meta::ArgumentMeta forceArgMeta(
			"force",
			"Force exit without confirmation",
			ArgValue(false)
		);

		forceArgMeta.registerNameAlias("-f");
		forceArgMeta.registerNameAlias("--force");

		forceArgMeta.registerArgValueFactory(std::make_unique<cli::BoolFactory>());

		exitMeta.registerArgumentMeta(std::move(forceArgMeta));

		m_registry.registerCommandMeta(std::move(exitMeta));
	}

	// add-slide command
	{
		meta::CommandMeta addSlideMeta(
			"add-slide",
			"Adds new slide to the existing presentation",
			std::make_shared< factories::AddSlideCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument
		meta::ArgumentMeta atArgMeta(
			"at",
			"Position in the presentation to add new slide",
			ArgValue(m_presentation.slidesCount())
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		addSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// color argument
		meta::ArgumentMeta colorArgMeta(
			"color",
			"Background color of the slide",
			ArgValue(model::utils::White)
		);

		colorArgMeta.registerNameAlias("-c");
		colorArgMeta.registerNameAlias("--color");

		//colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorNameFactory>());
		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBFactory>());
		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBAFactory>());

		addSlideMeta.registerArgumentMeta(std::move(colorArgMeta));

		m_registry.registerCommandMeta(std::move(addSlideMeta));
	}

	// remove-slide command
	{
		meta::CommandMeta removeSlideMeta(
			"remove-slide",
			"Removes a slide from the existing presentation",
			std::make_shared<factories::RemoveSlideCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument
		meta::ArgumentMeta atArgMeta(
			"at",
			"Position in the presentation to remove slide",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		removeSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		m_registry.registerCommandMeta(std::move(removeSlideMeta));
	}

	// edit-slide command
	{
		meta::CommandMeta editSlideMeta(
			"edit-slide",
			"Edits an existing slide in the presentation",
			std::make_shared<factories::EditSlideCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument
		meta::ArgumentMeta atArgMeta(
			"at",
			"Position in the presentation to edit slide",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		editSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// color argument
		meta::ArgumentMeta colorArgMeta(
			"color",
			"Background color of the slide",
			true
		);

		colorArgMeta.registerNameAlias("-c");
		colorArgMeta.registerNameAlias("--color");

		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBFactory>());
		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBAFactory>());

		editSlideMeta.registerArgumentMeta(std::move(colorArgMeta));

		m_registry.registerCommandMeta(std::move(editSlideMeta));
	}

	// duplicate-slide command
	{
		meta::CommandMeta duplicateSlideMeta(
			"duplicate-slide",
			"Duplicates an existing slide in the presentation",
			std::make_shared<factories::DuplicateSlideCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument
		meta::ArgumentMeta atArgMeta(
			"at",
			"Position in the presentation to duplicate slide",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		duplicateSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// to argument
		meta::ArgumentMeta toArgMeta(
			"to",
			"Position in the presentation to place duplicated slide",
			false
		);

		toArgMeta.registerNameAlias("-t");
		toArgMeta.registerNameAlias("--to");

		toArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		duplicateSlideMeta.registerArgumentMeta(std::move(toArgMeta));

		m_registry.registerCommandMeta(std::move(duplicateSlideMeta));
	}

	// move-slide command
	{
		meta::CommandMeta moveSlideMeta(
			"move-slide",
			"Moves an existing slide to a new position in the presentation",
			std::make_shared<factories::MoveSlideCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument
		meta::ArgumentMeta atArgMeta(
			"at",
			"Position in the presentation to move slide from",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		moveSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// to argument
		meta::ArgumentMeta toArgMeta(
			"to",
			"Position in the presentation to move slide to",
			true
		);
		toArgMeta.registerNameAlias("-t");
		toArgMeta.registerNameAlias("--to");

		toArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		moveSlideMeta.registerArgumentMeta(std::move(toArgMeta));

		m_registry.registerCommandMeta(std::move(moveSlideMeta));
	}

	// undo command
	{
		meta::CommandMeta undoMeta(
			"undo",
			"Undoes the last action",
			std::make_shared<factories::UndoCommandFactory>(m_actionManager)
		);

		m_registry.registerCommandMeta(std::move(undoMeta));
	}

	// redo command
	{
		meta::CommandMeta redoMeta(
			"redo",
			"Redoes the last undone action",
			std::make_shared<factories::RedoCommandFactory>(m_actionManager)
		);

		m_registry.registerCommandMeta(std::move(redoMeta));
	}

	// help command
	{
		meta::CommandMeta helpMeta(
			"help",
			"Shows help information for commands",
			std::make_shared<factories::HelpCommandFactory>(m_registry, m_viewer)
		);

		meta::ArgumentMeta commandArgMeta(
			"command",
			"Name of the command to show help for",
			ArgValue(std::string{})
		);

		commandArgMeta.registerNameAlias("-c");
		commandArgMeta.registerNameAlias("--command");

		commandArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

		helpMeta.registerArgumentMeta(std::move(commandArgMeta));

		m_registry.registerCommandMeta(std::move(helpMeta));
	}
}