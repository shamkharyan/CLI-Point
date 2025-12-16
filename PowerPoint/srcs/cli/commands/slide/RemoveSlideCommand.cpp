#include "cli/commands/slide/RemoveSlideCommand.h"
#include "core/ActionManager.h"
#include "core/actions/slide/RemoveSlideAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::core;
using namespace ppt::cli::cmds;

RemoveSlideCommand::RemoveSlideCommand(
	ActionManager& actionManager, 
	model::Presentation& presentation, 
	std::size_t at) :
	m_actionManager(actionManager), 
	m_presentation(presentation),
	m_at(at) 
{ }

void RemoveSlideCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Slide index out of bounds");

	auto action = std::make_unique<act::RemoveSlideAction>(m_presentation, m_at);
	
	m_actionManager.doAction(std::move(action));
}
