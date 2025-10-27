#include "controller/commands/AddSlideCommand.h"
#include "controller/commands/ACommand.h"

#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <stdexcept>

AddSlideCommand::AddSlideCommand(AppContext& context, std::optional<std::size_t> at, Color bgColor) :
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
