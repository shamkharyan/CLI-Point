#include "cli/meta/CommandMeta.h"
#include "cli/meta/ArgumentMeta.h"

using namespace ppt::cli::meta;

CommandMeta::CommandMeta(
	const std::string& name,
	const std::string& description,
	const std::shared_ptr<factories::ICommandFactory>& factory
) 	: m_name(name),
	  m_description(description),
	  m_factory(factory)
{
}

const ArgumentMeta* CommandMeta::getArgumentMeta(const std::string& argName) const
{
	auto it = m_aliasIndexes.find(argName);
	if (it == m_aliasIndexes.end())
		return nullptr;
	return &m_argMetas[it->second];
}

void CommandMeta::registerArgumentMeta(ArgumentMeta argMeta)
{
	for (const auto& alias : argMeta.getNameAliases())
		m_aliasIndexes[alias] = m_argMetas.size();

	m_argMetas.push_back(std::move(argMeta));
}
