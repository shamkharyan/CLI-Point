#include "cli/CommandRegistry.h"

using namespace ppt::cli;

CommandRegistry& CommandRegistry::instance()
{
	static CommandRegistry obj;
	return obj;
}

void CommandRegistry::registerFactory(const std::string& name, std::shared_ptr<factories::ICommandFactory> factory)
{
	m_factories[name] = std::move(factory);
}

std::shared_ptr<factories::ICommandFactory> CommandRegistry::getFactory(const std::string& name) const
{
	auto it = m_factories.find(name);
	if (it == m_factories.end())
		return nullptr;
	return it->second;
}

