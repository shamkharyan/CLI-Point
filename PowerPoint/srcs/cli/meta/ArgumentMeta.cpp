#include "cli/meta/ArgumentMeta.h"
#include "cli/parsing/ArgValue.h"

#include <stdexcept>

using namespace ppt::cli::meta;
using namespace ppt::cli;

ArgumentMeta::ArgumentMeta(
	const std::string canonicalName,
	const std::string& description,
	bool isRequired,
	std::optional<ArgValue> defaultValue) :
	m_canonicalName(canonicalName),
	m_description(description),
	m_isRequired(isRequired),
	m_defaultValue(defaultValue)
{
}

bool ArgumentMeta::isValidValue(const std::vector<std::string>& values) const
{
	for (const auto& factory : m_argValueFactories)
	{
		if (factory->canParse(values))
			return true;
	}
	return false;
}

ArgValue ArgumentMeta::parseValue(const std::vector<std::string>& values) const
{
	for (const auto& factory : m_argValueFactories)
	{
		if (factory->canParse(values))
			return factory->parse(values);
	}

	throw std::runtime_error("No suitable factory found to parse argument value");
}

void ArgumentMeta::registerNameAlias(const std::string& alias) 
{
	m_nameAliases.push_back(alias); 
}

void ArgumentMeta::registerArgValueFactory(std::unique_ptr<IArgValueFactory> factory) 
{ 
	m_argValueFactories.push_back(std::move(factory)); 
}
