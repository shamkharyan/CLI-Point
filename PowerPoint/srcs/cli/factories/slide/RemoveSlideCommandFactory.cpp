#include "cli/factories/slide/RemoveSlideCommandFactory.h"
#include "cli/commands/slide/RemoveSlideCommand.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

RemoveSlideCommandFactory::RemoveSlideCommandFactory(
	core::ActionManager& actionManager, 
	model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> RemoveSlideCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));

	return std::make_unique<cmds::RemoveSlideCommand>(m_actionManager, m_presentation, at);
}