#include "cli/parsing/factories/ColorRGBAFactory.h"

#include <stdexcept>
#include <string>
#include <cctype>

using namespace ppt::cli;

namespace
{
	bool isNumber(const std::string& s)
	{
		if (s.empty())
			return false;

		for (char c : s)
		{
			if (!std::isdigit(static_cast<unsigned char>(c)))
				return false;
		}
		return true;
	}

	int parseChannel(const std::string& s)
	{
		if (!isNumber(s))
			throw std::invalid_argument("RGBA value must be a number");

		int v = std::stoi(s);
		if (v < 0 || v > 255)
			throw std::out_of_range("RGBA value must be in range [0, 255]");

		return v;
	}
}

bool ColorRGBAFactory::canCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 4)
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

ArgValue ColorRGBAFactory::create(const std::vector<std::string>& argValue) const
{
	if (!canCreate(argValue))
		throw std::invalid_argument("Invalid RGBA color format");

	model::utils::Color color;

	color.r = parseChannel(argValue[0]);
	color.g = parseChannel(argValue[1]);
	color.b = parseChannel(argValue[2]);
	color.a = parseChannel(argValue[3]);

	return color;
}

std::string ColorRGBAFactory::typeName() const
{
	return argValueTypeName(model::utils::Color{});
}
