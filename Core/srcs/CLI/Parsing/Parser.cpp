#include "controller/parsing/Parser.h"
#include "controller/parsing/Tokenizer.h"

#include "model/AppContext.h"
#include "CommandRegistry.h"

Parser::Parser(AppContext& context, std::istream& stream) : m_context(context), m_stream(stream) {}

std::unique_ptr<Command> Parser::parse()
{
	Tokenizer tokenizer(m_stream);
	auto& registry = CommandRegistry::instance();

	auto cmdName = tokenizer.getNextToken();
	if (!cmdName.has_value())
		throw std::runtime_error("Invalid syntax");

	auto factory = registry.getFactory(cmdName.value());

	return factory(m_stream, m_context);
}

void Parser::resetStream()
{
	m_stream.clear();
	m_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}