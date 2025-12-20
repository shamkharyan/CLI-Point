#include "cli/parsing/parsers/ShapeTypeParser.h"
#include "utils/factories/ShapeTypeFactory.h"
#include "model/ShapeData.h"

using namespace ppt::utils::fact;
using namespace ppt::cli;

std::optional<ArgValue> ShapeTypeParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

	try
	{
		auto shapeType = ShapeTypeFactory::create(argValue[0]);
		return ArgValue(shapeType);
	}
	catch (...) {}

	return std::nullopt;
}

std::string ShapeTypeParser::typeName() const
{
	return "ShapeType";
}

