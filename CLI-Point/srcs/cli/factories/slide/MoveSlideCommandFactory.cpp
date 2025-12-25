#include "cli/factories/slide/MoveSlideCommandFactory.h"
#include "cli/commands/slide/MoveSlideCommand.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

MoveSlideCommandFactory::MoveSlideCommandFactory(core::ActionManager& actionManager, model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> MoveSlideCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));
	auto to = std::get<std::size_t>(rcmd.arguments.at("to"));

	return std::make_unique<cmds::MoveSlideCommand>(m_actionManager, m_presentation, at, to);
}