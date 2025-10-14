#include "controller/parsing/Parser.h"
#include "controller/parsing/Tokenizer.h"

#include "model/AppContext.h"
#include "CommandRegistry.h"
#include "viewer/CLIViewer.h"

Parser::Parser(AppContext& context, std::istream& istream) : 
	m_context(context),
	m_istream(istream),
	m_tokenizer(istream)
{ }

std::unique_ptr<Command> Parser::parse()
{
	auto& registry = CommandRegistry::instance();
	m_tokenizer.reset();

	auto token = m_tokenizer.getNextToken();
	if (token.type == Token::Type::EOL)
		return nullptr;
	if (token.type != Token::Type::Word)
		throw std::runtime_error("Invalid input");

	auto factory = registry.getFactory(token.value);

	return factory(m_tokenizer, m_context);
}