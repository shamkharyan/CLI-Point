#include "controller/parsing/Parser.h"
#include "controller/parsing/Tokenizer.h"

#include "model/AppContext.h"
#include "CommandRegistry.h"
#include "viewer/CLIViewer.h"

#include <unordered_set>

Parser::Parser(AppContext& context, std::istream& istream) : 
	m_context(context),
	m_istream(istream),
	m_tokenizer(istream)
{ }

std::unique_ptr<ACommand> Parser::parse()
{
	auto& registry = CommandRegistry::instance();
	m_tokenizer.reset();

	auto cmdName = m_tokenizer.getNextToken();
	if (cmdName.type == Token::Type::EOL)
		return nullptr;
	if (cmdName.type != Token::Type::Word)
		throw std::runtime_error("Invalid input");
	if (!registry.findCommand(cmdName.value))
		throw std::runtime_error("Unknown command: " + cmdName.value);


	// std::unordered_map<std::string, std::vector<std::string>> args;

	

	auto factory = registry.getFactory(cmdName.value);

	return factory(m_tokenizer, m_context);
}