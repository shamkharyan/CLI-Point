#include "cli/commands/slide/DuplicateSlideCommand.h"
#include "core/ActionManager.h"
#include "core/actions/slide/AddSlideAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

DuplicateSlideCommand::DuplicateSlideCommand(
	core::ActionManager& actionManager,
	model::Presentation& presentation,
	std::size_t at,
	std::size_t to) :
	m_actionManager(actionManager),
	m_presentation(presentation),
	m_at(at),
	m_to(to)
{
}

void DuplicateSlideCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Source slide index out of bounds");

	if (m_to > m_presentation.slidesCount())
		throw ExecutionError("Target index out of bounds");

	auto duplicatedSlide = std::make_shared<Slide>(*m_presentation.getSlide(m_at));
	auto action = std::make_unique<act::AddSlideAction>(m_presentation, duplicatedSlide, m_to);

	m_actionManager.doAction(std::move(action));
}