#include "cli/parsing/factories/ColorNameFactory.h"

using namespace ppt::cli;

std::optional<ArgValue> ColorNameFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

	const std::string& colorName = argValue[0];
	auto it = m_colorMap.find(colorName);
	if (it == m_colorMap.end())
		return std::nullopt;

	return it->second;
}

std::string ColorNameFactory::typeName() const
{
	return "Color";
}

