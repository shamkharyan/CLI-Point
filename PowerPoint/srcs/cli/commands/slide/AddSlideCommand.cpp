#include "cli/commands/slide/AddSlideCommand.h"
#include "core/ActionManager.h"
#include "core/actions/slide/AddSlideAction.h"
#include "core/actions/slide/AddLayerAction.h"
#include "core/actions/GroupAction.h"
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

	auto pSlide = std::make_shared<Slide>(m_color);
	auto pLayer = std::make_shared<SlideLayer>();

	auto groupAction = std::make_unique<act::GroupAction>();
	groupAction->addAction(std::make_unique<act::AddSlideAction>(m_presentation, pSlide, m_at));
	groupAction->addAction(std::make_unique<act::AddLayerAction>(pLayer, pSlide, 0));

	m_actionManager.doAction(std::move(groupAction));
}
