#include "cli/meta/ArgumentMeta.h"
#include "cli/parsing/factories/ArgValue.h"

#include <stdexcept>

using namespace ppt::cli::meta;
using namespace ppt::cli;

ArgumentMeta::ArgumentMeta(
	const std::string canonicalName,
	const std::string& description,
	bool isRequired) :
	m_canonicalName(canonicalName),
	m_description(description),
	m_isRequired(isRequired)
{
}

ArgumentMeta::ArgumentMeta(
	const std::string canonicalName,
	const std::string& description,
	ArgValue defaultValue) :
	m_canonicalName(canonicalName),
	m_description(description),
	m_isRequired(false),
	m_defaultValue(std::move(defaultValue))
{
}

void ArgumentMeta::registerNameAlias(const std::string& alias) 
{
	m_nameAliases.push_back(alias); 
}

void ArgumentMeta::registerArgValueFactory(std::shared_ptr<IArgValueFactory> factory) 
{ 
	m_argValueFactories.push_back(std::move(factory)); 
}
