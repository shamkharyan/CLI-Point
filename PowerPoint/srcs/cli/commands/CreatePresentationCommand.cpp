#include "cli/commands/CreatePresentationCommand.h"
#include "model/PPModel.h"
#include "core/actions/CreatePresentationAction.h"
#include "core/ActionManager.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;

CreatePresentationCommand::CreatePresentationCommand(viewer::IViewer& viewer, const std::optional<std::string>& name) :
	m_viewer(viewer),
	m_name(name)
{
}

void CreatePresentationCommand::execute()
{
	auto& manager = model::PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::CreatePresentationAction>(m_viewer, m_name.value_or("Untitled"));
	if (action->doAction())
		manager.append(std::move(action));
}