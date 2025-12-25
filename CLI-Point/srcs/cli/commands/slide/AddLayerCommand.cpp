#include "core/actions/slide/AddLayerAction.h"

#include "cli/commands/slide/AddLayerCommand.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::cli::cmds;

AddLayerCommand::AddLayerCommand(
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

void AddLayerCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Slide index out of bounds");
	
	auto pSlide = m_presentation.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Slide not found");

	auto pLayer = std::make_shared<ppt::model::SlideLayer>();
	auto action = std::make_unique<core::act::AddLayerAction>(pLayer, pSlide, m_zIndex);
	m_actionManager.doAction(std::move(action));
}