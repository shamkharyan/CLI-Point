#include "cli/commands/shape/RemoveShapeCommand.h"
#include "core/actions/shape/RemoveShapeAction.h"
#include "model/Slide.h"
#include "model/SlideLayer.h"

#include "cli/commands/ExecutionError.h"

using namespace ppt::cli::cmds;


RemoveShapeCommand::RemoveShapeCommand(
	model::Presentation& model,
	core::ActionManager& actionManager,
	std::size_t at,
	std::size_t id) :
	m_model(model),
	m_actionManager(actionManager),
	m_at(at),
	m_id(id)
{
}

void RemoveShapeCommand::execute()
{
	if (m_at >= m_model.slidesCount())
		throw ExecutionError("Slide index out of bounds");

	auto pSlide = m_model.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Slide not found");

	for (auto& layer : *pSlide)
	{
		for (auto& shape : *layer)
		{
			if (shape->id == m_id)
			{
				auto action = std::make_unique<core::act::RemoveShapeAction>(layer, m_id);
				m_actionManager.doAction(std::move(action));
				return;
			}
		}
	}
	throw ExecutionError("Shape not found");
}