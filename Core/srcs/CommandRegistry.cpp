#include "CommandRegistry.h"
#include "AllCommands.h"
#include <stdexcept>
#include <optional>

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

	auto exitFactory = [](Tokenizer& tok, AppContext& context, IViewer& viewer)
		{
			bool force = false;
			while (true)
			{
				auto token = tok.getNextToken();
				if (token.type == Token::Type::EOL)
					break;
				else if (token.value == "-f")
					force = true;
				else
					throw std::runtime_error("Invalid argument: " + token.value);
			}
			return std::make_unique<ExitCommand>(context, viewer, force);
		};

	registry.registerCommand("exit", exitFactory);

	auto createPresentationFactory = [](Tokenizer& tok, AppContext& context, IViewer& viewer)
		{
			std::string name = "Untitled";

			while (true)
			{
				auto token = tok.getNextToken();
				if (token.type == Token::Type::EOL)
					break;
				else if (token.value == "-name")
				{
					auto val = tok.getNextToken();
					if (val.type == Token::Type::EOL)
						throw std::runtime_error("Empty argument value");
					else if (val.type == Token::Type::Error)
						throw std::runtime_error("Invalid argument value: " + val.value);
					name = val.value;
				}
				else
					throw std::runtime_error("Invalid argument: " + token.value);
			}
			return std::make_unique<CreatePresentationCommand>(context, viewer, name);
		};

	registry.registerCommand("create", createPresentationFactory);
}

