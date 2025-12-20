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

	return std::make_unique<cmds::AddShapeCommand>(m_presentation, m_actionManager, m_registry, at, data, zIndex);
}
