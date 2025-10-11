#include "CommandRegistry.h"
#include "AllCommands.h"
#include <stdexcept>

#include "controller/parsing/Tokenizer.h"

CommandRegistry& CommandRegistry::instance()
{
	static CommandRegistry obj;
	return obj;
}

void CommandRegistry::registerCommand(const std::string& name, CommandFactory factory)
{
	m_factories[name] = std::move(factory);
}

CommandFactory CommandRegistry::getFactory(const std::string& name) const
{
	auto it = m_factories.find(name);
	if (it == m_factories.end())
		throw std::runtime_error("Unknown command: " + name);
	return it->second;
}

void registerMainCommands()
{
	auto& registry = CommandRegistry::instance();

	auto exitFactory = [](std::istream& is, AppContext& context)
		{
			Tokenizer tok(is);

			if (!is.eof() && tok.getNextToken())
				throw std::runtime_error("Exit command don't have arguments");
			return std::make_unique<ExitCommand>(context);
		};

	registry.registerCommand("exit", exitFactory);
}

