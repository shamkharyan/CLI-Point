#include "cli/factories/utility/RedoCommandFactory.h"
#include "cli/commands/utility/RedoCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

RedoCommandFactory::RedoCommandFactory(core::ActionManager& actionManager) :
	m_actionManager(actionManager)
{
}

std::unique_ptr<cmds::ICommand> RedoCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	return std::make_unique<cmds::RedoCommand>(m_actionManager);
}