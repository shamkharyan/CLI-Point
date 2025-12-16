#include "cli/meta/CommandRegistry.h"

using namespace ppt::cli;

const meta::CommandMeta* CommandRegistry::getCommandMeta(const std::string& name) const noexcept
{
	auto it = m_aliasIndexes.find(name);
	if (it == m_aliasIndexes.end())
		return nullptr;
	return &m_commands[it->second];
}


void CommandRegistry::registerCommandMeta(meta::CommandMeta cmdMeta)
{
	m_aliasIndexes[cmdMeta.getName()] = m_commands.size();
	m_commands.push_back(std::move(cmdMeta));
}