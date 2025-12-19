#include "cli/parsing/factories/ColorRGBFactory.h"

#include <stdexcept>
#include <string>
#include <cstdlib>

using namespace ppt::cli;

namespace
{
	bool isNumber(const std::string& s)
	{
		if (s.empty())
			return false;

		for (char c : s)
		{
			if (!std::isdigit(c))
				return false;
		}
		return true;
	}

	std::uint8_t parseChannel(const std::string& s)
	{
		if (!isNumber(s))
			throw std::invalid_argument("RGB value must be a number");

		std::size_t idx = 0;
		int v = std::stoi(s, &idx);
		if (idx != s.size() || v < 0 || v > 255)
			throw std::out_of_range("RGB value must be in range [0, 255]");

		return static_cast<std::uint8_t>(v);
	}
}

std::optional<ArgValue> ColorRGBFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 3 || argValue.size() != 4)
		return std::nullopt;
	try
	{
		auto r = parseChannel(argValue[0]);
		auto g = parseChannel(argValue[1]);
		auto b = parseChannel(argValue[2]);
		auto a = (argValue.size() == 4) ? parseChannel(argValue[3]) : static_cast<std::uint8_t>(255);

		return model::utils::Color(r, g, b, a);
	}
	catch (const std::exception&)
	{
		return std::nullopt;
	}
}

std::string ColorRGBFactory::typeName() const
{
	return "Color";
}
