#include "cli/parsing/parsers/ColorParser.h"
#include "utils/factories/ColorNameFactory.h"

#include <stdexcept>

using namespace ppt::utils::fact;
using namespace ppt::cli;

namespace
{
	std::uint8_t createUInt8T(const std::string& rawValue)
	{
		auto value = std::stoul(rawValue);
		if (value > 255)
			throw std::out_of_range("Value out of range for uint8_t: " + rawValue);
		return static_cast<std::uint8_t>(value);
	}
}

std::optional<ArgValue> ColorParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() == 1)
	{
		try
		{
			auto color = ColorNameFactory::create(argValue[0]);
			return ArgValue(color);
		}
		catch (...) {}
	}
	if (argValue.size() == 3 || argValue.size() == 4)
	{
		try
		{
			auto r = createUInt8T(argValue[0]);
			auto g = createUInt8T(argValue[1]);
			auto b = createUInt8T(argValue[2]);
			if (argValue.size() == 4)
			{
				auto a = createUInt8T(argValue[3]);
				return ArgValue(model::utils::Color(r, g, b, a));
			}
			return ArgValue(model::utils::Color(r, g, b));
		}
		catch (...) {}
	}

	return std::nullopt;
}

std::string ColorParser::typeName() const
{
	return "color";
}
