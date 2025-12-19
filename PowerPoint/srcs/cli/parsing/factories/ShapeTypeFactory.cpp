#include "cli/parsing/factories/ShapeTypeFactory.h"
#include "model/ShapeData.h"

using namespace ppt::cli;

std::optional<ArgValue> ShapeTypeFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

	const std::string& shapeTypeName = argValue[0];
	auto it = m_shapeTypeMap.find(shapeTypeName);
	if (it == m_shapeTypeMap.end())
		return std::nullopt;
	return it->second;
}

std::string ShapeTypeFactory::typeName() const
{
	return "ShapeType";
}

