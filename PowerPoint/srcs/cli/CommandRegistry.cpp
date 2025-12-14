#include "cli/CommandRegistry.h"

using namespace ppt::cli;

const meta::CommandMeta* CommandRegistry::getCommandMeta(const std::string& name) const noexcept
{
    auto it = m_commands.find(name);
    return it == m_commands.end() ? nullptr : &it->second;
}


void CommandRegistry::registerCommandMeta(meta::CommandMeta cmdMeta)
{
	m_commands.emplace(cmdMeta.getName(), std::move(cmdMeta));
}