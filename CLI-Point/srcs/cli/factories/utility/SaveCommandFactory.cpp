#include "cli/factories/utility/SaveCommandFactory.h"
#include "cli/commands/utility/SaveCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

SaveCommandFactory::SaveCommandFactory(
	const model::Presentation& presentation, 
	const ser::SerializerRegistry& registry,
	core::ActionManager& actionManager) :
	m_presentation(presentation),
	m_registry(registry),
	m_actionManager(actionManager)
{
}

std::unique_ptr<cmds::ICommand> SaveCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	std::string path = std::get<std::string>(rcmd.arguments.at("path"));

	return std::make_unique<cmds::SaveCommand>(m_presentation, m_registry, m_actionManager, path);
}