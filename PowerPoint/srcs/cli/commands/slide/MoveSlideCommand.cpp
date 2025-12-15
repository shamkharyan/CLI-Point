//#include "cli/commands/slide/MoveSlideCommand.h"
//#include "model/PPModel.h"
//#include "viewer/IViewer.h"
//#include "core/ActionManager.h"
//#include "core/actions/slide/MoveSlideAction.h"
//
//#include <stdexcept>
//
//using namespace ppt::core;
//using namespace ppt::cli::cmds;
//using namespace ppt::model;
//
//MoveSlideCommand::MoveSlideCommand(std::optional<std::size_t> at, std::size_t to) :
//	m_at(at),
//	m_to(to)
//{
//}
//
//void MoveSlideCommand::execute()
//{
//	auto& manager = PPModel::instance().getContext().getActionManager();
//	auto action = std::make_unique<act::MoveSlideAction>(m_at, m_to);
//	if (action->doAction())
//		manager.append(std::move(action));
//}
