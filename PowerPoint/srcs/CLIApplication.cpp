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
#include "cli/parsing/factories/ShapeTypeFactory.h"
#include "cli/parsing/factories/CoordFactory.h"

#include "cli/factories/utility/ExitCommandFactory.h"
#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/factories/slide/RemoveSlideCommandFactory.h"
#include "cli/factories/slide/EditSlideCommandFactory.h"
#include "cli/factories/slide/DuplicateSlideCommandFactory.h"
#include "cli/factories/slide/MoveSlideCommandFactory.h"
#include "cli/factories/slide/AddLayerCommandFactory.h"
#include "cli/factories/slide/RemoveLayerCommandFactory.h"
#include "cli/factories/slide/MoveLayerCommandFactory.h"
#include "cli/factories/shape/AddShapeCommandFactory.h"
#include "cli/factories/shape/RemoveShapeCommandFactory.h"
#include "cli/factories/utility/SaveCommandFactory.h"
#include "cli/factories/utility/OpenCommandFactory.h"
#include "cli/factories/utility/UndoCommandFactory.h"
#include "cli/factories/utility/RedoCommandFactory.h"
#include "cli/factories/utility/HelpCommandFactory.h"

#include "serialization/JSONSerializer.h"
#include "serialization/JSONDeserializer.h"

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
	registerSerializers();
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

		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorNameFactory>());
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

	// add-layer command
	{
		meta::CommandMeta addLayerMeta(
			"add-layer",
			"Adds a new layer to a slide",
			std::make_shared<factories::AddLayerCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide to add the layer to",
			true
		);
		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");
		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());
		addLayerMeta.registerArgumentMeta(std::move(atArgMeta));

		// z-index argument (layer index)
		meta::ArgumentMeta zIndexArgMeta(
			"z-index",
			"Z-Index of the layer to add",
			ArgValue(static_cast<std::size_t>(0))
		);

		zIndexArgMeta.registerNameAlias("-z");
		zIndexArgMeta.registerNameAlias("--z-index");
		zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());
		addLayerMeta.registerArgumentMeta(std::move(zIndexArgMeta));

		m_registry.registerCommandMeta(std::move(addLayerMeta));
	}

	// remove-layer command
	{
		meta::CommandMeta removeLayerMeta(
			"remove-layer",
			"Removes a layer from a slide",
			std::make_shared<factories::RemoveLayerCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide to remove the layer from",
			true
		);
		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");
		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());
		removeLayerMeta.registerArgumentMeta(std::move(atArgMeta));

		// z-index argument (layer index)
		meta::ArgumentMeta zIndexArgMeta(
			"z-index",
			"Z-Index of the layer to remove",
			true
		);
		zIndexArgMeta.registerNameAlias("-z");
		zIndexArgMeta.registerNameAlias("--z-index");
		zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());
		removeLayerMeta.registerArgumentMeta(std::move(zIndexArgMeta));
		m_registry.registerCommandMeta(std::move(removeLayerMeta));
	}

	// move-layer command
	{
		meta::CommandMeta moveLayerMeta(
			"move-layer",
			"Moves a layer within a slide",
			std::make_shared<factories::MoveLayerCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide containing the layer to move",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		moveLayerMeta.registerArgumentMeta(std::move(atArgMeta));

		// from-z argument (current layer index)
		meta::ArgumentMeta fromZArgMeta(
			"z-from",
			"Current Z-Index of the layer to move",
			true
		);

		fromZArgMeta.registerNameAlias("-f");
		fromZArgMeta.registerNameAlias("--z-from");

		fromZArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		moveLayerMeta.registerArgumentMeta(std::move(fromZArgMeta));

		// to-z argument (new layer index)
		meta::ArgumentMeta toZArgMeta(
			"z-to",
			"New Z-Index of the layer to move",
			true
		);

		toZArgMeta.registerNameAlias("-t");
		toZArgMeta.registerNameAlias("--z-to");

		toZArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		moveLayerMeta.registerArgumentMeta(std::move(toZArgMeta));

		m_registry.registerCommandMeta(std::move(moveLayerMeta));
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

	// add-shape command
	{
		meta::CommandMeta addShapeMeta(
			"add-shape",
			"Adds a new shape to a slide",
			std::make_shared<factories::AddShapeCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide to add the shape to",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");
		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());
		addShapeMeta.registerArgumentMeta(std::move(atArgMeta));

		// type argument (shape type)
		meta::ArgumentMeta typeArgMeta(
			"type",
			"Type of shape",
			true
		);

		typeArgMeta.registerNameAlias("-t");
		typeArgMeta.registerNameAlias("--type");

		typeArgMeta.registerArgValueFactory(std::make_shared<cli::ShapeTypeFactory>());

		addShapeMeta.registerArgumentMeta(std::move(typeArgMeta));

		// position argument (x and y)
		meta::ArgumentMeta positionArgMeta(
			"position",
			"Position of the shape as 'x,y' coordinates",
			true
		);

		positionArgMeta.registerNameAlias("-p");
		positionArgMeta.registerNameAlias("--position");

		positionArgMeta.registerArgValueFactory(std::make_shared<cli::CoordFactory>());

		addShapeMeta.registerArgumentMeta(std::move(positionArgMeta));

		// size argument (width and height)
		meta::ArgumentMeta sizeArgMeta(
			"size",
			"Size of the shape as 'width,height'",
			true
		);

		sizeArgMeta.registerNameAlias("-s");
		sizeArgMeta.registerNameAlias("--size");

		sizeArgMeta.registerArgValueFactory(std::make_shared<cli::CoordFactory>());

		addShapeMeta.registerArgumentMeta(std::move(sizeArgMeta));

		// fill-color argument (optional)
		meta::ArgumentMeta fillColorArgMeta(
			"fill-color",
			"Fill color of the shape",
			ArgValue(model::utils::Black)
		);

		fillColorArgMeta.registerNameAlias("--fill-color");

		fillColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBFactory>());
		fillColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorNameFactory>());

		addShapeMeta.registerArgumentMeta(std::move(fillColorArgMeta));

		// outline-color argument (optional)
		meta::ArgumentMeta outlineColorArgMeta(
			"outline-color",
			"Outline color of the shape",
			ArgValue(model::utils::Red)
		);

		outlineColorArgMeta.registerNameAlias("--outline-color");
		outlineColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorRGBFactory>());
		outlineColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorNameFactory>());

		addShapeMeta.registerArgumentMeta(std::move(outlineColorArgMeta));

		// outline-width argument (optional)
		meta::ArgumentMeta outlineWidthArgMeta(
			"outline-width",
			"Outline width of the shape",
			ArgValue(1.0f)
		);

		outlineWidthArgMeta.registerNameAlias("--outline-width");
		outlineWidthArgMeta.registerArgValueFactory(std::make_shared<cli::FloatFactory>());

		addShapeMeta.registerArgumentMeta(std::move(outlineWidthArgMeta));

		// z-index argument (optional)
		meta::ArgumentMeta zIndexArgMeta(
			"z-index",
			"Z-index (layer) of the shape",
			ArgValue(static_cast<std::size_t>(0))
		);

		zIndexArgMeta.registerNameAlias("-z");
		zIndexArgMeta.registerNameAlias("--z-index");

		zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		addShapeMeta.registerArgumentMeta(std::move(zIndexArgMeta));

		m_registry.registerCommandMeta(std::move(addShapeMeta));
	}

	// remove-shape command
	{
		meta::CommandMeta removeShapeMeta(
			"remove-shape",
			"Removes a shape from a slide",
			std::make_shared<factories::RemoveShapeCommandFactory>(m_actionManager, m_presentation)
		);

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide to remove the shape from",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		removeShapeMeta.registerArgumentMeta(std::move(atArgMeta));

		// id argument (shape id)
		meta::ArgumentMeta idArgMeta(
			"id",
			"ID of the shape to remove",
			true
		);

		idArgMeta.registerNameAlias("-i");
		idArgMeta.registerNameAlias("--id");

		idArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTFactory>());

		removeShapeMeta.registerArgumentMeta(std::move(idArgMeta));

		m_registry.registerCommandMeta(std::move(removeShapeMeta));
	}

	// save command
	{
		meta::CommandMeta saveMeta(
			"save",
			"Saves the current presentation to a file",
			std::make_shared<factories::SaveCommandFactory>(m_presentation, m_serializerRegistry)
		);

		meta::ArgumentMeta pathArgMeta(
			"path",
			"Path to save the presentation file",
			true
		);

		pathArgMeta.registerNameAlias("-p");
		pathArgMeta.registerNameAlias("--path");

		pathArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

		saveMeta.registerArgumentMeta(std::move(pathArgMeta));

		m_registry.registerCommandMeta(std::move(saveMeta));
	}

	// open command
	{
		meta::CommandMeta openMeta(
			"open",
			"Opens a presentation file",
			std::make_shared<factories::OpenCommandFactory>(m_presentation, m_serializerRegistry)
		);

		meta::ArgumentMeta pathArgMeta(
			"path",
			"Path to open the presentation file",
			true
		);

		pathArgMeta.registerNameAlias("-p");
		pathArgMeta.registerNameAlias("--path");

		pathArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

		openMeta.registerArgumentMeta(std::move(pathArgMeta));

		m_registry.registerCommandMeta(std::move(openMeta));
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
			false
		);

		commandArgMeta.registerNameAlias("-c");
		commandArgMeta.registerNameAlias("--command");

		commandArgMeta.registerArgValueFactory(std::make_shared<cli::StringFactory>());

		helpMeta.registerArgumentMeta(std::move(commandArgMeta));

		m_registry.registerCommandMeta(std::move(helpMeta));
	}
}

void CLIApplication::registerSerializers()
{
	m_serializerRegistry.registerPair(
		".json",
		std::make_shared<ser::JSONSerializer>(),
		std::make_shared<ser::JSONDeserializer>()
	);
}