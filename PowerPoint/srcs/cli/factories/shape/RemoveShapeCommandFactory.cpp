#include "cli/factories/shape/RemoveShapeCommandFactory.h"
#include "cli/commands/shape/RemoveShapeCommand.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"
#include "model/utils/GeometryData.h"
#include "model/utils/ShapeType.h"
#include "model/utils/StyleData.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

RemoveShapeCommandFactory::RemoveShapeCommandFactory(
	core::ActionManager& actionManager,
	model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> RemoveShapeCommandFactory::createCommand(const ParsedRawCommand& args)
{
	auto at = std::get<std::size_t>(args.arguments.at("at"));
	auto shapeId = std::get<std::size_t>(args.arguments.at("id"));

	return std::make_unique<cmds::RemoveShapeCommand>(m_presentation, m_actionManager, at, shapeId);
}