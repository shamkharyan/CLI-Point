#include "cli/utils/ArgParser.h"
#include "cli/utils/Converter.h"

#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"

using namespace ppt::cli::utils;
using namespace ppt::model::utils;
	
bool ArgParser::parseFlag(const std::string& name, const std::vector<std::string>& values)
{
	if (!values.empty())
		throw err::InvalidArgumentValueException("'" + name + "' does not take any values");
	return true;
}

std::size_t ArgParser::parseNumber(const std::string& name, const std::vector<std::string>& values)
{
	if (values.empty())
		throw err::MissingArgumentValueException(name);
	if (values.size() > 1)
		throw err::InvalidArgumentValueException("'" + name + "' takes exactly one numeric value");

	auto number = Converter::stringToSizeT(values[0]);
	if (!number)
		throw err::InvalidArgumentValueException("'" + name + "' expects a positive integer, got '" + values[0] + "'");

	return number.value();
}

Coord ArgParser::parseCoord(const std::string& name, const std::vector<std::string>& values)
{
	if (values.size() != 2)
		throw err::InvalidArgumentValueException("'" + name + "' takes exactly 2 numeric values");

	auto x = Converter::stringToSizeT(values[0]);
	auto y = Converter::stringToSizeT(values[1]);

	if (!x || !y)
	{
		std::string badValue = !x ? values[0] : values[1];
		throw err::InvalidArgumentValueException("'" + name + "' expects two positive integers, got '" + badValue + "'");
	}

	return ppt::model::utils::Coord{ x.value(), y.value() };
}

std::string ArgParser::parseString(const std::string& name, const std::vector<std::string>& values)
{
	if (values.empty())
		throw err::MissingArgumentValueException(name);
	if (values.size() > 1)
		throw err::InvalidArgumentValueException("'" + name + "' takes exactly one text value");
	return values[0];
}

Color ArgParser::parseColor(const std::string& name, const std::vector<std::string>& values)
{
	std::optional<Color> color;
	if (values.size() == 1)
		color = Converter::stringToColor(values[0]);
	else if (values.size() == 3)
		color = Converter::vectorToColor(values);
	else
		throw err::InvalidArgumentValueException("'" + name + "' takes 1 or 3 values");

	if (!color)
	{
		if (values.size() == 1)
			throw err::InvalidArgumentValueException("'" + name + "' invalid color value: '" + values[0] + "'");
		else
			throw err::InvalidArgumentValueException("'" + name + "' invalid color value: '" + values[0] + values[1] + values[2] + "'");
	}

	return color.value();
}
