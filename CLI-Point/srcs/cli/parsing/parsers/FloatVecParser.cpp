#include "cli/parsing/parsers/FloatVecParser.h"
#include "cli/parsing/parsers/FloatParser.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

std::optional<ArgValue> FloatVecParser::tryCreate(const std::vector<std::string>& argValue) const
{
	std::vector<float> values;
	FloatParser parser;
	
	for (const auto& strVal : argValue)
	{
		if (auto fVal = parser.tryCreate({ strVal }))
			values.push_back(std::get<float>(*fVal));
		else
			return std::nullopt;
	}

	return ArgValue{ std::move(values) };
}

std::string FloatVecParser::typeName() const
{
	return "float...";
}
