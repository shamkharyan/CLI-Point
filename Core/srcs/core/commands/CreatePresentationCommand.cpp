#include "core/commands/CreatePresentationCommand.h"
#include "core/commands/AConfirmCommand.h"
#include "model/AppContext.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

CreatePresentationCommand::CreatePresentationCommand(AppContext& context, viewer::IViewer& viewer, const std::string& name) :
	cmds::AConfirmCommand(context, viewer),
	m_name(name)
{}

void CreatePresentationCommand::execute()
{
	if (m_context.presentation)
	{
		auto ans = m_viewer.askConfirmation("Do you want to rewrite old presentation?");
		if (ans && ans.value())
			m_context.presentation = std::make_unique<Presentation>(m_name);
	}
	else
		m_context.presentation = std::make_unique<Presentation>(m_name);
}