#include "CreatePresentationCommand.h"
#include "Command.h"
#include "model/AppContext.h"
#include <stdexcept>


CreatePresentationCommand::CreatePresentationCommand(AppContext& context, const std::string& name) :
	ConfirmCommand(context),
	m_name(name)
{}

Command::Result CreatePresentationCommand::execute()
{
	if (m_context.presentation)
		return Command::Result::Confirmation;
	m_context.presentation = std::make_unique<Presentation>(m_name);
	return Command::Result::Success;
}

std::string CreatePresentationCommand::confirmQuestion() const
{
	return "Do you want to rewrite old presentation?";
}

Command::Result CreatePresentationCommand::confirm(bool ans)
{
	if (ans)
		m_context.presentation = std::make_unique<Presentation>(m_name);
	return Command::Result::Success;
}