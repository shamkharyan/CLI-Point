#include "cli/factories/shape/AddShapeCommandFactory.h"
#include "cli/commands/shape/AddShapeCommand.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"
#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"

#include "cli/commands/ExecutionError.h"

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

void AddShapeCommandFactory::prepareAdjustments(const std::string& type, std::vector<float>& adjustments)
{
    const auto* shapeMeta = m_registry.getShapeMeta(type);
    if (!shapeMeta)
        throw ExecutionError("Unknown shape type: " + type);

    if (adjustments.size() > shapeMeta->adjustmentCount()) 
    {
        throw ExecutionError("Too many adjustments for " + type +
            ". Expected max " + std::to_string(shapeMeta->adjustmentCount()));
    }

    size_t i = 0;
    for (auto it = shapeMeta->begin(); it != shapeMeta->end(); ++it, ++i) 
    {
        float value;
        if (i < adjustments.size()) 
        {
            value = adjustments[i];
            if (value < it->getMinValue() || value > it->getMaxValue())
            {
                throw ExecutionError("Adjustment '" + it->getName() +
                    "' out of range [" + std::to_string(it->getMinValue()) +
                    ".." + std::to_string(it->getMaxValue()) + "]");
            }
        }
        else
            adjustments.push_back(it->getDefaultValue());
    }
}

std::unique_ptr<cmds::ICommand> AddShapeCommandFactory::createCommand(const ParsedRawCommand& args)
{
	model::ShapeData data;

	auto at = std::get<std::size_t>(args.arguments.at("at"));
	data.type = std::get<std::string>(args.arguments.at("type"));
	data.geometry.x = std::get<float>(args.arguments.at("x"));
	data.geometry.y = std::get<float>(args.arguments.at("y"));
	data.geometry.width = std::get<float>(args.arguments.at("width"));
	data.geometry.height = std::get<float>(args.arguments.at("height"));
	auto zIndex = std::get<std::size_t>(args.arguments.at("z-index"));

	if (args.arguments.count("fill-color"))
		data.style.fillColor = std::get<model::utils::Color>(args.arguments.at("fill-color"));
	if (args.arguments.count("outline-color"))
		data.style.outlineColor = std::get<model::utils::Color>(args.arguments.at("outline-color"));
	if (args.arguments.count("outline-width"))
		data.style.outlineWidth = std::get<float>(args.arguments.at("outline-width"));

	data.text = std::get<std::string>(args.arguments.at("text"));
	data.textStyle.fontName = std::get<std::string>(args.arguments.at("font-name"));
	data.textStyle.fontSize = std::get<float>(args.arguments.at("font-size"));
	data.textStyle.fontColor = std::get<model::utils::Color>(args.arguments.at("font-color"));

	if (args.arguments.count("adjustments"))
		data.adjustments = std::get<std::vector<float>>(args.arguments.at("adjustments"));

	prepareAdjustments(data.type, data.adjustments);

	return std::make_unique<cmds::AddShapeCommand>(
		m_presentation,
		m_actionManager,
		at,
		data,
		zIndex
	);
}
