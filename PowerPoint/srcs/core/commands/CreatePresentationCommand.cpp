#include "core/commands/CreatePresentationCommand.h"
#include "model/PPModel.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

CreatePresentationCommand::CreatePresentationCommand(viewer::IViewer& viewer, const std::string& name) :
	m_viewer(viewer),
	m_name(name)
{}

void CreatePresentationCommand::execute()
{
	auto& context = PPModel::instance().getContext();
	bool shouldRewrite = true;

	if (context.presentation)
	{
		auto ans = m_viewer.askConfirmation("Do you want to rewrite old presentation?");
		shouldRewrite = ans && ans.value();
	}
	if (shouldRewrite)
		context.presentation = std::make_unique<Presentation>(m_name);
}