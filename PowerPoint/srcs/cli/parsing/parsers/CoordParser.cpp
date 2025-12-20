#include "cli/parsing/parsers/CoordParser.h"
#include "model/utils/Coord.h"

using namespace ppt::cli;

std::optional<ArgValue> CoordParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 2)
		return std::nullopt;

	try
	{
		auto x = std::stoull(argValue[0]);
		auto y = std::stoull(argValue[1]);
		return ArgValue(model::utils::Coord{ x, y });
	}
	catch (...) {}

	return std::nullopt;
}

std::string CoordParser::typeName() const
{
	return "Coord";
}