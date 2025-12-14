#pragma once

#include "cli/meta/CommandMeta.h"
#include "cli/meta/ArgumentMeta.h"


using namespace ppt::cli::meta;
using namespace ppt::cli::factories;

CommandMeta::CommandMeta(
	const std::string& name,
	const std::string& description,
	const std::shared_ptr<factories::ICommandFactory>& factory
) 	: m_name(name),
	  m_description(description),
	  m_factory(factory)
{
}

const ArgumentMeta* CommandMeta::getArgumentMeta(const std::string& argName) const noexcept
{
	auto it = m_aliasIndexes.find(argName);
	return it != m_aliasIndexes.end() ? it->second : nullptr;
}

void CommandMeta::registerArgumentMeta(ArgumentMeta argMeta)
{
	m_argMetas.push_back(std::move(argMeta));
	m_aliasIndexes[m_argMetas.back().getCanonicalName()] = &m_argMetas.back();
}