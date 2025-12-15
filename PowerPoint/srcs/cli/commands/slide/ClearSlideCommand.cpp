//#include "cli/commands/slide/ClearSlideCommand.h"
//#include "core/ActionManager.h"
//#include "core/actions/slide/ClearSlideAction.h"
//#include "model/PPModel.h"
//
//using namespace ppt::core;
//using namespace ppt::cli::cmds;
//
//ClearSlideCommand::ClearSlideCommand(std::optional<std::size_t> at) : m_at(at) {}
//
//void ClearSlideCommand::execute()
//{
//	auto& manager = model::PPModel::instance().getContext().getActionManager();
//	auto action = std::make_unique<act::ClearSlideAction>(m_at);
//	if (action->doAction())
//		manager.append(std::move(action));
//}
