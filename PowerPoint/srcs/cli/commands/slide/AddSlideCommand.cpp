#include "cli/commands/slide/AddSlideCommand.h"
#include "core/ActionManager.h"
#include "core/actions/slide/AddSlideAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

AddSlideCommand::AddSlideCommand(
	core::ActionManager& actionManager,
	model::Presentation& presentation,
	std::size_t at,
	model::utils::Color color) :
	m_actionManager(actionManager),
	m_presentation(presentation),
	m_at(at),
	m_color(color)
{ }

void AddSlideCommand::execute()
{
	if (m_at > m_presentation.slidesCount())
		throw ExecutionError("Slide index out of bounds");

	auto slide = std::make_shared<Slide>(m_color);
	auto action = std::make_unique<act::AddSlideAction>(m_presentation, slide, m_at);

	m_actionManager.doAction(std::move(action));
}
