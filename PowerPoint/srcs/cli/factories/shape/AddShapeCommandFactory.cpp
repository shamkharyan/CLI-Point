#include "cli/factories/shape/AddShapeCommandFactory.h"
#include "cli/commands/shape/AddShapeCommand.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"
#include "model/utils/GeometryData.h"
#include "model/utils/ShapeType.h"
#include "model/utils/StyleData.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

AddShapeCommandFactory::AddShapeCommandFactory(
	core::ActionManager& actionManager,
	model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> AddShapeCommandFactory::createCommand(const ParsedRawCommand& args)
{
	model::utils::GeometryData geometryData;
	model::utils::StyleData styleData;

	auto at = std::get<std::size_t>(args.arguments.at("at"));
	auto shapeType = std::get<model::utils::ShapeType>(args.arguments.at("type"));
	geometryData.topLeft = std::get<model::utils::Coord>(args.arguments.at("position"));
	geometryData.size = std::get<model::utils::Coord>(args.arguments.at("size"));
	auto zIndex = std::get<std::size_t>(args.arguments.at("z-index"));

	return std::make_unique<cmds::AddShapeCommand>(m_presentation, m_actionManager, at, shapeType, geometryData, styleData, zIndex);
}
