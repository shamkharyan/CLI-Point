#include "cli/parsing/CommandParser.h"

#include "cli/CommandRegistry.h"
#include "cli/parsing/SemanticAnalizer.h"
#include "cli/parsing/SyntaxParser.h"
#include "cli/parsing/RawCommand.h"

using namespace ppt::cli;

CommandParser::CommandParser(
	const CommandRegistry& registry,
	std::istream& istream) :
	m_commandRegistry(registry),
	m_istream(istream),
	m_syntaxParser(istream),
	m_semanticAnalyzer(registry)
{
}

std::unique_ptr<cmds::ICommand> CommandParser::parseCommand()
{
	auto rawCommand = m_syntaxParser.parse();
	if (rawCommand.name.empty())
		return nullptr;

	auto validatedRawCommand = m_semanticAnalyzer.analyze(rawCommand);

	auto factory = m_commandRegistry.getCommandMeta(validatedRawCommand.name)->getFactory();

	return factory->createCommand(validatedRawCommand);
}
