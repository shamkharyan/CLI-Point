#include "cli/commands/shape/AddShapeCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/shape/AddShapeAction.h"
#include "core/actions/utils/AddShapeParams.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

AddShapeCommand::AddShapeCommand(const act::utils::AddShapeParams& params) : m_params(params) {}

void AddShapeCommand::execute()
{
	auto& manager = PPModel::instance().getContext().getActionManager();
	auto action = std::make_unique<act::AddShapeAction>(m_params);
	if (action->doAction())
		manager.append(std::move(action));
}
