#include "cli/commands/slide/MoveSlideCommand.h"
#include "core/ActionManager.h"
#include "core/actions/GroupAction.h"
#include "core/actions/slide/AddSlideAction.h"
#include "core/actions/slide/RemoveSlideAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

MoveSlideCommand::MoveSlideCommand(
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

void MoveSlideCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Source slide index out of bounds");

	if (m_to > m_presentation.slidesCount())
		throw ExecutionError("Target index out of bounds");

	if (m_at == m_to)
		return;

	if (m_at < m_to)
		--m_to;

	auto action = std::make_unique<act::GroupAction>();
	auto slideToMove = m_presentation.getSlide(m_at);

	action->addAction(std::make_unique<act::RemoveSlideAction>(m_presentation, m_at));
	action->addAction(std::make_unique<act::AddSlideAction>(m_presentation, slideToMove, m_to));

	m_actionManager.doAction(std::move(action));
}