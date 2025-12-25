#include "cli/commands/slide/EditSlideCommand.h"
#include "core/actions/slide/EditSlideAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::cli::cmds;
using namespace ppt::core::act;

EditSlideCommand::EditSlideCommand(
	core::ActionManager& actionManager,
	model::Presentation& presentation,
	std::size_t at,
	model::utils::Color color) :
	m_actionManager(actionManager),
	m_presentation(presentation),
	m_at(at),
	m_color(color)
{
}

void EditSlideCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Slide index out of bounds");

	auto pSlide = m_presentation.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Slide not found");

	auto action = std::make_unique<EditSlideAction>(m_presentation, pSlide, m_at, m_color);
}