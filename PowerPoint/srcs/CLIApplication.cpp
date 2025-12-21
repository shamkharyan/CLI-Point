#include "CLIApplication.h"

#include "cli/meta/CommandRegistry.h"
#include "cli/CLIViewer.h"
#include "cli/CLIController.h"
#include "cli/meta/CommandMeta.h"
#include "cli/meta/ArgumentMeta.h"

#include "cli/parsing/parsers/BoolParser.h"
#include "cli/parsing/parsers/SizeTParser.h"
#include "cli/parsing/parsers/FloatParser.h"
#include "cli/parsing/parsers/FloatVecParser.h"
#include "cli/parsing/parsers/ColorParser.h"
#include "cli/parsing/parsers/StringParser.h"
#include "cli/parsing/parsers/ShapeTypeParser.h"

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
#include "cli/factories/utility/ExportCommandFactory.h"
#include "cli/factories/utility/UndoCommandFactory.h"
#include "cli/factories/utility/RedoCommandFactory.h"
#include "cli/factories/utility/HelpCommandFactory.h"

#include "serialization/serializers/JSONSerializer.h"
#include "serialization/deserializers/JSONDeserializer.h"
#include "serialization/exporters/SVGExporter.h"

#include "visualization/factories/RectangleShapeFactory.h"
#include "visualization/factories/EllipseShapeFactory.h"
#include "visualization/factories/TriangleShapeFactory.h"
#include "visualization/factories/StarShapeFactory.h"
#include "visualization/factories/ParallelogramShapeFactory.h"
#include "visualization/factories/TrapezoidShapeFactory.h"

#include "visualization/meta/AdjustmentMeta.h"
#include "visualization/meta/ShapeMeta.h"
#include "visualization/meta/ShapeRegistry.h"

#include <iostream>
#include <fstream>

using namespace ppt;
using namespace ppt::cli;

void CLIApplication::parseArguments(int argc, char* argv[] = nullptr)
{
	std::cout << argc << '\n';
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg == "-i" && i + 1 < argc)
		{
			static std::ifstream fin;
			fin.open(argv[++i]);
			if (!fin.is_open())
				throw std::runtime_error("Cannot open input file");
			m_viewer.setIStream(&fin);
		}
		else if (arg == "-o" && i + 1 < argc)
		{
			static std::ofstream fout;
			fout.open(argv[++i]);
			if (!fout.is_open())
				throw std::runtime_error("Cannot open output file");
			m_viewer.setOStream(&fout);
		}
	}
}

CLIApplication& CLIApplication::instance(int argc, char* argv[])
{
	static CLIApplication app;
	app.parseArguments(argc, argv);
	return app;
}

int CLIApplication::execute()
{
	return m_controller.run();
}

CLIApplication::CLIApplication() :
	m_presentation("Untitled"),
	m_viewer(m_presentation, &std::cin, &std::cout),
	m_controller(m_viewer, m_registry, m_presentation)
{
	registerShapes();
	registerSerializers();
	registerDeserializers();
	registerExporters();
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

		forceArgMeta.registerArgValueFactory(std::make_unique<cli::BoolParser>());

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
			false
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		addSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// color argument
		meta::ArgumentMeta colorArgMeta(
			"color",
			"Background color of the slide",
			ArgValue(model::utils::White)
		);

		colorArgMeta.registerNameAlias("-c");
		colorArgMeta.registerNameAlias("--color");

		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorParser>());

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

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

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

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		editSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// color argument
		meta::ArgumentMeta colorArgMeta(
			"color",
			"Background color of the slide",
			true
		);

		colorArgMeta.registerNameAlias("-c");
		colorArgMeta.registerNameAlias("--color");

		colorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorParser>());

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

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		duplicateSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// to argument
		meta::ArgumentMeta toArgMeta(
			"to",
			"Position in the presentation to place duplicated slide",
			false
		);

		toArgMeta.registerNameAlias("-t");
		toArgMeta.registerNameAlias("--to");

		toArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

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

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		moveSlideMeta.registerArgumentMeta(std::move(atArgMeta));

		// to argument
		meta::ArgumentMeta toArgMeta(
			"to",
			"Position in the presentation to move slide to",
			true
		);
		toArgMeta.registerNameAlias("-t");
		toArgMeta.registerNameAlias("--to");

		toArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

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
		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());
		addLayerMeta.registerArgumentMeta(std::move(atArgMeta));

		// z-index argument (layer index)
		meta::ArgumentMeta zIndexArgMeta(
			"z-index",
			"Z-Index of the layer to add",
			ArgValue(static_cast<std::size_t>(0))
		);

		zIndexArgMeta.registerNameAlias("-z");
		zIndexArgMeta.registerNameAlias("--z-index");
		zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());
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
		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());
		removeLayerMeta.registerArgumentMeta(std::move(atArgMeta));

		// z-index argument (layer index)
		meta::ArgumentMeta zIndexArgMeta(
			"z-index",
			"Z-Index of the layer to remove",
			true
		);
		zIndexArgMeta.registerNameAlias("-z");
		zIndexArgMeta.registerNameAlias("--z-index");
		zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());
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

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		moveLayerMeta.registerArgumentMeta(std::move(atArgMeta));

		// from-z argument (current layer index)
		meta::ArgumentMeta fromZArgMeta(
			"z-from",
			"Current Z-Index of the layer to move",
			true
		);

		fromZArgMeta.registerNameAlias("-f");
		fromZArgMeta.registerNameAlias("--z-from");

		fromZArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		moveLayerMeta.registerArgumentMeta(std::move(fromZArgMeta));

		// to-z argument (new layer index)
		meta::ArgumentMeta toZArgMeta(
			"z-to",
			"New Z-Index of the layer to move",
			true
		);

		toZArgMeta.registerNameAlias("-t");
		toZArgMeta.registerNameAlias("--z-to");

		toZArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

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
			std::make_shared<factories::AddShapeCommandFactory>(m_actionManager, m_presentation, m_shapeRegistry)
		);

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide to add the shape to",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");
		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());
		addShapeMeta.registerArgumentMeta(std::move(atArgMeta));

		// type argument (shape type)
		meta::ArgumentMeta typeArgMeta(
			"type",
			"Type of shape",
			true
		);

		typeArgMeta.registerNameAlias("-t");
		typeArgMeta.registerNameAlias("--type");

		typeArgMeta.registerArgValueFactory(std::make_shared<cli::ShapeTypeParser>(m_shapeRegistry));

		addShapeMeta.registerArgumentMeta(std::move(typeArgMeta));

		// x coord
		meta::ArgumentMeta xArgMeta(
			"x", 
			"X coordinate of the top-left corner", 
			true
		);

		xArgMeta.registerNameAlias("-x");
		xArgMeta.registerNameAlias("--x");
		xArgMeta.registerArgValueFactory(std::make_shared<cli::FloatParser>());
		addShapeMeta.registerArgumentMeta(std::move(xArgMeta));

		// y coord
		meta::ArgumentMeta yArgMeta(
			"y", 
			"Y coordinate of the top-left corner",
			true
		);

		yArgMeta.registerNameAlias("-y");
		yArgMeta.registerNameAlias("--y");
		yArgMeta.registerArgValueFactory(std::make_shared<cli::FloatParser>());
		addShapeMeta.registerArgumentMeta(std::move(yArgMeta));

		// width
		meta::ArgumentMeta wArgMeta("width", "Width of the shape (positive)", true);
		wArgMeta.registerNameAlias("-w");
		wArgMeta.registerNameAlias("--width");
		wArgMeta.registerArgValueFactory(std::make_shared<cli::FloatParser>());
		addShapeMeta.registerArgumentMeta(std::move(wArgMeta));

		// height
		meta::ArgumentMeta hArgMeta("height", "Height of the shape (positive)", true);
		hArgMeta.registerNameAlias("-h");
		hArgMeta.registerNameAlias("--height");
		hArgMeta.registerArgValueFactory(std::make_shared<cli::FloatParser>());
		addShapeMeta.registerArgumentMeta(std::move(hArgMeta));

		// fill-color argument (optional)
		meta::ArgumentMeta fillColorArgMeta(
			"fill-color",
			"Fill color of the shape",
			ArgValue(model::utils::Black)
		);

		fillColorArgMeta.registerNameAlias("--fill-color");

		fillColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorParser>());

		addShapeMeta.registerArgumentMeta(std::move(fillColorArgMeta));

		// outline-color argument (optional)
		meta::ArgumentMeta outlineColorArgMeta(
			"outline-color",
			"Outline color of the shape",
			ArgValue(model::utils::Red)
		);

		outlineColorArgMeta.registerNameAlias("--outline-color");
		outlineColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorParser>());

		addShapeMeta.registerArgumentMeta(std::move(outlineColorArgMeta));

		// outline-width argument (optional)
		meta::ArgumentMeta outlineWidthArgMeta(
			"outline-width",
			"Outline width of the shape",
			ArgValue(1.0f)
		);

		outlineWidthArgMeta.registerNameAlias("--outline-width");
		outlineWidthArgMeta.registerArgValueFactory(std::make_shared<cli::FloatParser>());

		addShapeMeta.registerArgumentMeta(std::move(outlineWidthArgMeta));

		// z-index argument (optional)
		meta::ArgumentMeta zIndexArgMeta(
			"z-index",
			"Z-index (layer) of the shape",
			ArgValue(static_cast<std::size_t>(0))
		);

		zIndexArgMeta.registerNameAlias("-z");
		zIndexArgMeta.registerNameAlias("--z-index");

		zIndexArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		addShapeMeta.registerArgumentMeta(std::move(zIndexArgMeta));

		// text argument (optional)
		meta::ArgumentMeta textArgMeta(
			"text",
			"Text to display inside the shape",
			ArgValue(std::string{})
		);

		textArgMeta.registerNameAlias("--text");
		textArgMeta.registerArgValueFactory(std::make_shared<cli::StringParser>());
		addShapeMeta.registerArgumentMeta(std::move(textArgMeta));

		// font-name argument (optional)
		meta::ArgumentMeta fontNameArgMeta(
			"font-name",
			"Font name for the text",
			ArgValue(std::string{ "Arial" })
		);

		fontNameArgMeta.registerNameAlias("--font-name");
		fontNameArgMeta.registerArgValueFactory(std::make_shared<cli::StringParser>());
		addShapeMeta.registerArgumentMeta(std::move(fontNameArgMeta));

		// font-size argument (optional)
		meta::ArgumentMeta fontSizeArgMeta(
			"font-size",
			"Font size for the text",
			ArgValue(12.0f)
		);

		fontSizeArgMeta.registerNameAlias("--font-size");
		fontSizeArgMeta.registerArgValueFactory(std::make_shared<cli::FloatParser>());
		addShapeMeta.registerArgumentMeta(std::move(fontSizeArgMeta));

		// font-color argument (optional)
		meta::ArgumentMeta fontColorArgMeta(
			"font-color",
			"Font color for the text",
			ArgValue(model::utils::Black)
		);

		fontColorArgMeta.registerNameAlias("--font-color");
		fontColorArgMeta.registerArgValueFactory(std::make_shared<cli::ColorParser>());
		addShapeMeta.registerArgumentMeta(std::move(fontColorArgMeta));


		// adjustments
		meta::ArgumentMeta adjustmentsMeta(
			"adjustments",
			"Adjustments for the shape",
			false
		);

		adjustmentsMeta.registerNameAlias("--adjustments");
		adjustmentsMeta.registerArgValueFactory(std::make_shared<cli::FloatVecParser>());

		for (auto it = m_shapeRegistry.begin(); it != m_shapeRegistry.end(); ++it)
		{
			const auto& shapeMeta = *it;

			if (shapeMeta.begin() == shapeMeta.end())
			{
				continue;
			}

			// Заголовок для конкретной фигуры
			std::string headNote = shapeMeta.getName() + ":";
			adjustmentsMeta.addNote(headNote);

			// Проходим по каждому adjustment этой фигуры
			for (auto adjIt = shapeMeta.begin(); adjIt != shapeMeta.end(); ++adjIt)
			{
				const auto& adj = *adjIt;

				// Форматируем строку: имя, описание и дефолт
				// Пример: "  - inner-ratio: Ratio of inner radius (default: 0.5)"
				std::string adjNote = "  - " + adj.getName() + ": " + adj.getDescription();
				adjNote += " (default: " + std::to_string(adj.getDefaultValue()) + ")";

				adjustmentsMeta.addNote(adjNote);
			}
		}

		addShapeMeta.registerArgumentMeta(std::move(adjustmentsMeta));

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

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		removeShapeMeta.registerArgumentMeta(std::move(atArgMeta));

		// id argument (shape id)
		meta::ArgumentMeta idArgMeta(
			"id",
			"ID of the shape to remove",
			true
		);

		idArgMeta.registerNameAlias("-i");
		idArgMeta.registerNameAlias("--id");

		idArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

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

		pathArgMeta.registerArgValueFactory(std::make_shared<cli::StringParser>());

		saveMeta.registerArgumentMeta(std::move(pathArgMeta));

		m_registry.registerCommandMeta(std::move(saveMeta));
	}

	// open command
	{
		meta::CommandMeta openMeta(
			"open",
			"Opens a presentation file",
			std::make_shared<factories::OpenCommandFactory>(m_presentation, m_deserializerRegistry)
		);

		meta::ArgumentMeta pathArgMeta(
			"path",
			"Path to open the presentation file",
			true
		);

		pathArgMeta.registerNameAlias("-p");
		pathArgMeta.registerNameAlias("--path");

		pathArgMeta.registerArgValueFactory(std::make_shared<cli::StringParser>());

		openMeta.registerArgumentMeta(std::move(pathArgMeta));

		m_registry.registerCommandMeta(std::move(openMeta));
	}

	// export command
	{
		meta::CommandMeta exportMeta(
			"export",
			"Exports a slide object to a file",
			std::make_shared<factories::ExportCommandFactory>(m_presentation, m_exporterRegistry)
		);

		// path argument (required)
		meta::ArgumentMeta pathArgMeta(
			"path",
			"Path to export the slide object",
			true
		);

		pathArgMeta.registerNameAlias("-p");
		pathArgMeta.registerNameAlias("--path");

		pathArgMeta.registerArgValueFactory(std::make_shared<cli::StringParser>());

		exportMeta.registerArgumentMeta(std::move(pathArgMeta));

		// at argument (slide index)
		meta::ArgumentMeta atArgMeta(
			"at",
			"Index of the slide to export",
			true
		);

		atArgMeta.registerNameAlias("-a");
		atArgMeta.registerNameAlias("--at");

		atArgMeta.registerArgValueFactory(std::make_shared<cli::SizeTParser>());

		exportMeta.registerArgumentMeta(std::move(atArgMeta));

		m_registry.registerCommandMeta(std::move(exportMeta));
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

		commandArgMeta.registerArgValueFactory(std::make_shared<cli::StringParser>());

		helpMeta.registerArgumentMeta(std::move(commandArgMeta));

		m_registry.registerCommandMeta(std::move(helpMeta));
	}
}

void CLIApplication::registerSerializers()
{
	m_serializerRegistry.registerSerializer(".json", std::make_shared<ser::JSONSerializer>());
}

void CLIApplication::registerDeserializers()
{
	m_deserializerRegistry.registerDeserializer(".json", std::make_shared<ser::JSONDeserializer>());
}

void CLIApplication::registerExporters()
{
	m_exporterRegistry.registerExporter(".svg", std::make_shared<ser::SVGExporter>(m_shapeRegistry));
}

void CLIApplication::registerShapes()
{
	// triangle
	{
		constexpr float k60deg = 1.0472f;
		constexpr float kPi = 3.14f;

		vis::ShapeMeta triangleMeta("triangle", std::make_shared<vis::TriangleShapeFactory>());
		triangleMeta.registerAdjustmentMeta({ "top-angle", "Top angle in radians", k60deg, 0.1f, kPi });
		m_shapeRegistry.registerShapeMeta(std::move(triangleMeta));
	}

	// star
	{
		vis::ShapeMeta starMeta("star", std::make_shared<vis::StarShapeFactory>());
		starMeta.registerAdjustmentMeta({ "inner-ratio", "Ratio of inner to outer radius", 0.5f, 0.05f, 0.95f });
		starMeta.registerAdjustmentMeta({ "points", "Number of star points", 5.0f, 3.0f, 100.0f });
		m_shapeRegistry.registerShapeMeta(std::move(starMeta));
	}

	// parallelogram
	{
		vis::ShapeMeta paraMeta("parallelogram", std::make_shared<vis::ParallelogramShapeFactory>());
		// Сдвиг от -1.0 до 1.0 (в долях от ширины)
		paraMeta.registerAdjustmentMeta({ "skew", "Horizontal skew ratio", 0.3f, -1.0f, 1.0f });
		m_shapeRegistry.registerShapeMeta(std::move(paraMeta));
	}

	// trapezoid
	{
		vis::ShapeMeta trapMeta("trapezoid", std::make_shared<vis::TrapezoidShapeFactory>());
		trapMeta.registerAdjustmentMeta({ "top-width-ratio", "Top width ratio", 0.5f, 0.0f, 1.0f });
		m_shapeRegistry.registerShapeMeta(std::move(trapMeta));
	}
}