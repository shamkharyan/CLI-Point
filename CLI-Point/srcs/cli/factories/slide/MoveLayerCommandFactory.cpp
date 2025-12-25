#include "cli/factories/slide/MoveLayerCommandFactory.h"
#include "cli/commands/slide/MoveLayerCommand.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

MoveLayerCommandFactory::MoveLayerCommandFactory(core::ActionManager& actionManager, model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> MoveLayerCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));
	auto zFrom = std::get<std::size_t>(rcmd.arguments.at("z-from"));
	auto zTo = std::get<std::size_t>(rcmd.arguments.at("z-to"));

	return std::make_unique<cmds::MoveLayerCommand>(m_actionManager, m_presentation, at, zFrom, zTo);
}