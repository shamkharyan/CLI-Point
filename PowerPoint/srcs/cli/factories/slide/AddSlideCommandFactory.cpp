#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/commands/slide/AddSlideCommand.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

AddSlideCommandFactory::AddSlideCommandFactory(core::ActionManager& actionManager, model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> AddSlideCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	std::size_t at;
	if (rcmd.arguments.find("at") == rcmd.arguments.end())
		at = m_presentation.slidesCount();
	else
		at = std::get<std::size_t>(rcmd.arguments.at("at"));

	auto color = std::get<model::utils::Color>(rcmd.arguments.at("color"));

	return std::make_unique<cmds::AddSlideCommand>(m_actionManager, m_presentation, at, color);
}