#include "cli/parsing/FloatFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

bool FloatFactory::canParse(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return false;

	try
	{
		size_t idx = 0;
		std::ignore = std::stof(argValue[0], &idx);
		return idx == argValue[0].size();
	}
	catch (...)
	{
		return false;
	}
}

ArgValue FloatFactory::parse(const std::vector<std::string>& argValue) const
{
	if (!canParse(argValue))
		throw std::invalid_argument("Invalid float value");

	float value = std::stof(argValue[0]);
	return value;
}

std::string FloatFactory::description() const
{
	return "Floating point value (e.g. 1.0, -0.25, 3.14)";
}
