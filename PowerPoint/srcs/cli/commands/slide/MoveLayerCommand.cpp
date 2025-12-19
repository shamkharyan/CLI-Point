#include "cli/commands/slide/MoveLayerCommand.h"
#include "core/ActionManager.h"
#include "core/actions/GroupAction.h"
#include "core/actions/slide/AddLayerAction.h"
#include "core/actions/slide/RemoveLayerAction.h"
#include "cli/commands/ExecutionError.h"

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

MoveLayerCommand::MoveLayerCommand(
	core::ActionManager& actionManager,
	model::Presentation& presentation,
	std::size_t at,
	std::size_t zFrom,
	std::size_t zTo) :
	m_actionManager(actionManager),
	m_presentation(presentation),
	m_zFrom(zFrom),
	m_zTo(zTo),
	m_at(at)
{
}

void MoveLayerCommand::execute()
{
	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Source slide index out of bounds");

	auto pSlide = m_presentation.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Source slide not found");

	if (m_zFrom >= pSlide->layersCount())
		throw ExecutionError("Source layer index out of bounds");

	if (m_zTo > pSlide->layersCount())
		throw ExecutionError("Target layer index out of bounds");

	if (m_zFrom == m_zTo)
		return;

	if (m_zFrom < m_zTo)
		--m_zTo;

	auto action = std::make_unique<act::GroupAction>();
	auto pLayerToMove = pSlide->getLayer(m_zFrom);
	if (!pLayerToMove)
		throw ExecutionError("Source layer not found");

	action->addAction(std::make_unique<act::RemoveLayerAction>(pSlide, m_zFrom));
	action->addAction(std::make_unique<act::AddLayerAction>(pLayerToMove, pSlide, m_zTo));

	m_actionManager.doAction(std::move(action));
}