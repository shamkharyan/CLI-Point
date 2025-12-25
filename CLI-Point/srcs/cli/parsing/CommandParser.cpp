#include "cli/parsing/CommandParser.h"

#include "cli/meta/CommandRegistry.h"
#include "cli/parsing/SemanticParser.h"
#include "cli/parsing/SyntaxParser.h"
#include "cli/parsing/RawCommand.h"

using namespace ppt::cli;

CommandParser::CommandParser(
	const CommandRegistry& registry,
	std::istream& istream) :
	m_commandRegistry(registry),
	m_istream(istream),
	m_syntaxParser(istream),
	m_semanticParser(registry)
{
}

std::unique_ptr<cmds::ICommand> CommandParser::parseCommand()
{
	auto rawCommand = m_syntaxParser.parse();
	if (rawCommand.name.empty())
		return nullptr;

	auto parsedRawCommand = m_semanticParser.parseRawCommand(rawCommand);

	auto factory = m_commandRegistry.getCommandMeta(parsedRawCommand.name)->getFactory();

	return factory->createCommand(parsedRawCommand);
}
