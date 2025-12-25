#include "cli/factories/slide/DuplicateSlideCommandFactory.h"
#include "cli/commands/slide/DuplicateSlideCommand.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

DuplicateSlideCommandFactory::DuplicateSlideCommandFactory(core::ActionManager& actionManager, model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> DuplicateSlideCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));

	std::size_t to;
	if (rcmd.arguments.find("to") == rcmd.arguments.end())
		to = at + 1;
	else
		to = std::get<std::size_t>(rcmd.arguments.at("to"));

	return std::make_unique<cmds::DuplicateSlideCommand>(m_actionManager, m_presentation, at, to);
}