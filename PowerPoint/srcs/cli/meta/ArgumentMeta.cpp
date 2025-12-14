#include "cli/meta/ArgumentMeta.h"
#include "cli/parsing/ArgValue.h"

#include <stdexcept>

using namespace ppt::cli::meta;
using namespace ppt::cli;

ArgumentMeta::ArgumentMeta(const std::string canonicalName,
	const std::string& description,
	bool isRequired,
	const std::vector<std::string>& defaultValues) :
	m_canonicalName(canonicalName),
	m_description(description),
	m_isRequired(isRequired),
	m_defaultValues(defaultValues)
{
}

bool ArgumentMeta::isValidValue(const std::vector<std::string>& values) const
{
	for (const auto& factory : m_argValueFactories)
	{
		if (factory.first->canParse(values))
			return true;
	}
	return false;
}

ArgValue ArgumentMeta::parseValue(const std::vector<std::string>& values) const
{
	int bestPriority = std::numeric_limits<int>::min();
	IArgValueFactory* bestFactory = nullptr;

	for (const auto& [factory, priority] : m_argValueFactories)
	{
		if (factory->canParse(values))
		{
			if (priority > bestPriority)
			{
				bestPriority = priority;
				bestFactory = factory.get();
			}
		}
	}

	if (!bestFactory)
		throw std::runtime_error("No suitable factory found to parse argument value");
	return bestFactory->parse(values);
}
