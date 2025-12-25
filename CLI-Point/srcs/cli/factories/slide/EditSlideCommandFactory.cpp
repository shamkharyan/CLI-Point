#include "cli/factories/slide/EditSlideCommandFactory.h"

#include "cli/commands/slide/EditSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

EditSlideCommandFactory::EditSlideCommandFactory(
	core::ActionManager& actionManager,
	model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> EditSlideCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));
	auto color = std::get<model::utils::Color>(rcmd.arguments.at("color"));

	return std::make_unique<cmds::EditSlideCommand>(m_actionManager, m_presentation, at, color);
}