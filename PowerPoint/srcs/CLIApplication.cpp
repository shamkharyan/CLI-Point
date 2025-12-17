#include "CLIApplication.h"

#include "cli/meta/CommandRegistry.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "cli/meta/CommandMeta.h"
#include "cli/meta/ArgumentMeta.h"

#include "cli/parsing/factories/BoolFactory.h"
#include "cli/parsing/factories/SizeTFactory.h"
#include "cli/parsing/factories/FloatFactory.h"
#include "cli/parsing/factories/ColorNameFactory.h"
#include "cli/parsing/factories/ColorRGBFactory.h"
#include "cli/parsing/factories/StringFactory.h"

#include "cli/factories/utility/ExitCommandFactory.h"
#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/factories/slide/RemoveSlideCommandFactory.h"
#include "cli/factories/slide/EditSlideCommandFactory.h"
#include "cli/factories/slide/DuplicateSlideCommandFactory.h"
#include "cli/factories/slide/MoveSlideCommandFactory.h"
#include "cli/factories/shape/AddShapeCommandFactory.h"
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

	//// add-shape command
	//{
	//	meta::CommandMeta addShapeMeta(
	//		"add-shape",
	//		"Adds a new shape to a slide",
	//		std::make_shared<factories::AddShapeCommandFactory>(m_actionManager, m_presentation)
	//	);

	//	// at argument (slide index)
	//	meta::ArgumentMeta atArgMeta(
	//		"at",
	//		"Index of the slide to add the shape to",
	//		true
	//	);

	//	atArgMeta.registerNameAlias("-a");
	//	atArgMeta.registerNameAlias("--at");

	//	atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(atArgMeta));

	//	// type argument (shape type)
	//	meta::ArgumentMeta typeArgMeta(
	//		"type",
	//		"Type of shape (rectangle, circle, or triangle)",
	//		true
	//	);

	//	typeArgMeta.registerNameAlias("-t");
	//	typeArgMeta.registerNameAlias("--type");

	//	typeArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(typeArgMeta));

	//	// x argument (position x)
	//	meta::ArgumentMeta xArgMeta(
	//		"x",
	//		"X coordinate of the shape position",
	//		true
	//	);

	//	xArgMeta.registerNameAlias("-x");
	//	xArgMeta.registerNameAlias("--x");

	//	xArgMeta.registerArgValueFactory(std::make_shared<cli::FloatFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(xArgMeta));

	//	// y argument (position y)
	//	meta::ArgumentMeta yArgMeta(
	//		"y",
	//		"Y coordinate of the shape position",
	//		true
	//	);

	//	yArgMeta.registerNameAlias("-y");
	//	yArgMeta.registerNameAlias("--y");

	//	yArgMeta.registerArgValueFactory(std::make_shared<cli::FloatFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(yArgMeta));

	//	// width argument
	//	meta::ArgumentMeta widthArgMeta(
	//		"width",
	//		"Width of the shape",
	//		true
	//	);

	//	widthArgMeta.registerNameAlias("-w");
	//	widthArgMeta.registerNameAlias("--width");

	//	widthArgMeta.registerArgValueFactory(std::make_shared<cli::FloatFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(widthArgMeta));

	//	// height argument
	//	meta::ArgumentMeta heightArgMeta(
	//		"height",
	//		"Height of the shape",
	//		true
	//	);

	//	heightArgMeta.registerNameAlias("-h");
	//	heightArgMeta.registerNameAlias("--height");

	//	heightArgMeta.registerArgValueFactory(std::make_shared<cli::FloatFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(heightArgMeta));

	//	// fill-color argument (optional)
	//	meta::ArgumentMeta fillColorArgMeta(
	//		"fill-color",
	//		"Fill color of the shape",
	//		ArgValue(model::utils::White)
	//	);

	//	fillColorArgMeta.registerNameAlias("-fc");
	//	fillColorArgMeta.registerNameAlias("--fill-color");

	//	fillColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(fillColorArgMeta));

	//	// outline-color argument (optional)
	//	meta::ArgumentMeta outlineColorArgMeta(
	//		"outline-color",
	//		"Outline color of the shape",
	//		ArgValue(model::utils::Black)
	//	);

	//	outlineColorArgMeta.registerNameAlias("-oc");
	//	outlineColorArgMeta.registerNameAlias("--outline-color");

	//	outlineColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(outlineColorArgMeta));

	//	// outline-width argument (optional)
	//	meta::ArgumentMeta outlineWidthArgMeta(
	//		"outline-width",
	//		"Outline width of the shape",
	//		ArgValue(1.0f)
	//	);

	//	outlineWidthArgMeta.registerNameAlias("-ow");
	//	outlineWidthArgMeta.registerNameAlias("--outline-width");

	//	outlineWidthArgMeta.registerArgValueFactory(std::make_shared<cli::FloatFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(outlineWidthArgMeta));

	//	// text argument (optional)
	//	meta::ArgumentMeta textArgMeta(
	//		"text",
	//		"Text content of the shape",
	//		false
	//	);

	//	textArgMeta.registerNameAlias("--text");

	//	textArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(textArgMeta));

	//	// z-index argument (optional)
	//	meta::ArgumentMeta zIndexArgMeta(
	//		"z-index",
	//		"Z-index (layer) of the shape",
	//		ArgValue(static_cast<std::size_t>(0))
	//	);

	//	zIndexArgMeta.registerNameAlias("-z");
	//	zIndexArgMeta.registerNameAlias("--z-index");

	//	zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

	//	addShapeMeta.registerArgumentMeta(std::move(zIndexArgMeta));

	//	m_registry.registerCommandMeta(std::move(addShapeMeta));
	//}

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
			false
		);

		commandArgMeta.registerNameAlias("-c");
		commandArgMeta.registerNameAlias("--command");

		commandArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

		helpMeta.registerArgumentMeta(std::move(commandArgMeta));

		m_registry.registerCommandMeta(std::move(helpMeta));
	}
}