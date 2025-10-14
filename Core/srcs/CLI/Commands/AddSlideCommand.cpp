#include "AddSlideCommand.h"

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "Command.h"

#include <stdexcept>

AddSlideCommand::AddSlideCommand(AppContext& context, int at) :
	Command(context),
	m_at(at)
{ }

Command::Result AddSlideCommand::execute()
{
	auto& presentation = m_context.presentation;
	if (!presentation)
		throw std::runtime_error("No presentation for adding a slide");
	std::size_t uat = static_cast<std::size_t>(m_at);
	if (m_at == -1)
		uat = presentation->slidesCount();
	presentation->addSlide(uat);
}
