#include "cli/factories/utility/UndoCommandFactory.h"
#include "cli/commands/utility/UndoCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

UndoCommandFactory::UndoCommandFactory(core::ActionManager& actionManager) :
	m_actionManager(actionManager)
{
}

std::unique_ptr<cmds::ICommand> UndoCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	return std::make_unique<cmds::UndoCommand>(m_actionManager);
}