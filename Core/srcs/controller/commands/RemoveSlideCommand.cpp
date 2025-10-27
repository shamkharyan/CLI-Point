#include "controller/commands/RemoveSlideCommand.h"
#include "controller/commands/ACommand.h"

#include "model/AppContext.h"
#include "viewer/IViewer.h"

#include <stdexcept>

RemoveSlideCommand::RemoveSlideCommand(AppContext& context, std::size_t at) :
	ACommand(context),
	m_at(at) { }

void RemoveSlideCommand::execute()
{
	auto& presentation = m_context.presentation;
	if (!presentation)
		throw std::runtime_error("No presentation for removing a slide");
	presentation->removeSlide(m_at);
}
