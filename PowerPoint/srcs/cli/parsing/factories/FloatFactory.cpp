#include "cli/parsing/factories/FloatFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

bool FloatFactory::canCreate(const std::vector<std::string>& argValue) const
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

ArgValue FloatFactory::create(const std::vector<std::string>& argValue) const
{
	if (!canCreate(argValue))
		throw std::invalid_argument("Invalid float value");

	float value = std::stof(argValue[0]);
	return value;
}

std::string FloatFactory::typeName() const
{
	return argValueTypeName(float{});
}
