#include "cli/factories/shape/AddShapeCommandFactory.h"
#include "cli/commands/shape/AddShapeCommand.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"
#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"
#include "visualization/ShapeRegistry.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

AddShapeCommandFactory::AddShapeCommandFactory(
	core::ActionManager& actionManager,
	model::Presentation& presentation,
	const vis::ShapeRegistry& registry) :
	m_actionManager(actionManager),
	m_presentation(presentation),
	m_registry(registry)
{
}

std::unique_ptr<cmds::ICommand> AddShapeCommandFactory::createCommand(const ParsedRawCommand& args)
{
    model::ShapeData data;

    auto at = std::get<std::size_t>(args.arguments.at("at"));
    data.type = std::get<std::string>(args.arguments.at("type"));
    data.geometry.topLeft = std::get<model::utils::Coord>(args.arguments.at("position"));
    data.geometry.size = std::get<model::utils::Coord>(args.arguments.at("size"));
    auto zIndex = std::get<std::size_t>(args.arguments.at("z-index"));

    if (args.arguments.count("fill-color"))
        data.style.fillColor = std::get<model::utils::Color>(args.arguments.at("fill-color"));
    if (args.arguments.count("outline-color"))
        data.style.outlineColor = std::get<model::utils::Color>(args.arguments.at("outline-color"));
    if (args.arguments.count("outline-width"))
        data.style.outlineWidth = std::get<float>(args.arguments.at("outline-width"));

    if (args.arguments.count("text"))
        data.text = std::get<std::string>(args.arguments.at("text"));
    if (args.arguments.count("font-name"))
        data.textStyle.fontName = std::get<std::string>(args.arguments.at("font-name"));
    if (args.arguments.count("font-size"))
        data.textStyle.fontSize = std::get<float>(args.arguments.at("font-size"));
    if (args.arguments.count("font-color"))
        data.textStyle.fontColor = std::get<model::utils::Color>(args.arguments.at("font-color"));

    return std::make_unique<cmds::AddShapeCommand>(
        m_presentation,
        m_actionManager,
        m_registry,
        at,
        data,
        zIndex
    );
}
