#include "cli/parsing/ColorRGBFactory.h"

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

	int parseChannel(const std::string& s)
	{
		if (!isNumber(s))
			throw std::invalid_argument("RGB value must be a number");

		int v = std::stoi(s);
		if (v < 0 || v > 255)
			throw std::out_of_range("RGB value must be in range [0, 255]");

		return v;
	}
}

bool ColorRGBFactory::canParse(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 3)
		return false;

	for (const auto& v : argValue)
	{
		if (!isNumber(v))
			return false;

		int value = std::stoi(v);
		if (value < 0 || value > 255)
			return false;
	}

	return true;
}

ArgValue ColorRGBFactory::parse(const std::vector<std::string>& argValue) const
{
	if (!canParse(argValue))
		throw std::invalid_argument("Invalid RGB color format");

	model::utils::Color color;

	color.r = parseChannel(argValue[0]);
	color.g = parseChannel(argValue[1]);
	color.b = parseChannel(argValue[2]);
	color.a = 255;

	return ArgValue(color);
}

std::string ColorRGBFactory::description() const
{
	return "RGB color value: <R> <G> <B>, where each channel is in range [0..255]";
}
