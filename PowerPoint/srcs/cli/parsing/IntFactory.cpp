#include "cli/parsing/IntFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

bool IntFactory::canParse(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return false;

	try
	{
		size_t idx = 0;
		std::stoi(argValue[0], &idx);
		return idx == argValue[0].size();
	}
	catch (...)
	{
		return false;
	}
}

ArgValue IntFactory::parse(const std::vector<std::string>& argValue) const
{
	if (!canParse(argValue))
		throw std::invalid_argument("Invalid integer value");

	int value = std::stoi(argValue[0]);
	return ArgValue(value);
}

std::string IntFactory::description() const
{
	return "Integer value (e.g. -10, 0, 42)";
}
