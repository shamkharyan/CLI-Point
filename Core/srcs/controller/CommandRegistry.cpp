#include "controller/CommandRegistry.h"

#include "controller/parsing/Tokenizer.h"
#include "controller/parsing/Converter.h"

#include "controller/factories/ExitCommandFactory.h"
#include "controller/factories/CreatePresentationCommandFactory.h"

CommandRegistry& CommandRegistry::instance()
{
	static CommandRegistry obj;
	return obj;
}

void CommandRegistry::registerFactory(const std::string& name, std::shared_ptr<ACommandFactory> factory)
{
	m_factories[name] = std::move(factory);
}

std::shared_ptr<ACommandFactory> CommandRegistry::getFactory(const std::string& name) const
{
	auto it = m_factories.find(name);
	if (it == m_factories.end())
		return nullptr;
	return it->second;
}

void registerMainCommands(AppContext& context, IViewer& viewer)
{
	auto& registry = CommandRegistry::instance();

	registry.registerFactory("exit", std::make_shared<ExitCommandFactory>(context, viewer));
	registry.registerFactory("create", std::make_shared<CreatePresentationCommandFactory>(context, viewer));
}

