#include "cli/factories/utility/OpenCommandFactory.h"
#include "cli/commands/utility/OpenCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

OpenCommandFactory::OpenCommandFactory(
	model::Presentation& presentation,
	const ser::SerializerRegistry& registry) :
	m_presentation(presentation),
	m_registry(registry)
{
}

std::unique_ptr<cmds::ICommand> OpenCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	std::string path = std::get<std::string>(rcmd.arguments.at("path"));

	return std::make_unique<cmds::OpenCommand>(m_presentation, m_registry, path);
}