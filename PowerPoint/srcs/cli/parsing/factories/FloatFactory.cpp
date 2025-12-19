#include "cli/parsing/factories/FloatFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

std::optional<ArgValue> FloatFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;
	try
	{
		size_t idx = 0;
		float value = std::stof(argValue[0], &idx);
		if (idx != argValue[0].size())
			return std::nullopt;
		return value;
	}
	catch (...)
	{
		return std::nullopt;
	}
}

std::string FloatFactory::typeName() const
{
	return "float";
}
