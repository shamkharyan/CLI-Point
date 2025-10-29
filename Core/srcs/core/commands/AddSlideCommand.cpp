#include "core/commands/AddSlideCommand.h"
#include "core/commands/ACommand.h"

#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

AddSlideCommand::AddSlideCommand(AppContext& context, std::optional<std::size_t> at, utils::Color bgColor) :
	ACommand(context),
	m_at(at),
	m_bgColor(bgColor)
{ }

void AddSlideCommand::execute()
{
	auto& presentation = m_context.presentation;
	if (!presentation)
		throw std::runtime_error("No presentation for adding a slide");
	if (!m_at)
		presentation->addSlide(std::make_unique<Slide>(), presentation->slidesCount());
	else
		presentation->addSlide(std::make_unique<Slide>(), m_at.value());
}
