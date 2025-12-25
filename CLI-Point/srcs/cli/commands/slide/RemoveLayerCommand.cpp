#include "cli/commands/slide/RemoveLayerCommand.h"

#include "core/actions/slide/RemoveLayerAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::cli::cmds;

RemoveLayerCommand::RemoveLayerCommand(
	core::ActionManager& actionManager,
	model::Presentation& presentation,
	std::size_t at,
	std::size_t zIndex) :
	m_actionManager(actionManager),
	m_presentation(presentation),
	m_at(at),
	m_zIndex(zIndex)
{
}

void RemoveLayerCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Slide index out of bounds");

	auto pSlide = m_presentation.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Slide not found");

	if (m_zIndex >= pSlide->layersCount())
		throw ExecutionError("Layer index out of bounds");

	auto action = std::make_unique<core::act::RemoveLayerAction>(pSlide, m_zIndex);
	m_actionManager.doAction(std::move(action));
}