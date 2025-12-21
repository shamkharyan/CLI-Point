#include "cli/parsing/parsers/ShapeTypeParser.h"

#include <stdexcept>

using namespace ppt::cli;

ShapeTypeParser::ShapeTypeParser(const vis::ShapeRegistry& registry) : m_registry(registry) {}

std::optional<ArgValue> ShapeTypeParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

	if (auto pFactory = m_registry.getShapeMeta(argValue[0]))
		return ArgValue(argValue[0]);

	return std::nullopt;
}

std::string ShapeTypeParser::typeName() const
{
	return "ShapeType";
}