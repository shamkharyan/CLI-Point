#pragma once

#include "IArgValueParser.h"

#include <unordered_map>

namespace ppt::cli
{
	class ShapeTypeParser : public IArgValueParser
	{
	public:
		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;
	};
}