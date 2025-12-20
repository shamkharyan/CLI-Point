#pragma once

#include "ArgValue.h"

#include <vector>
#include <string>
#include <optional>

namespace ppt::cli
{
	class IArgValueParser
	{
	public:
		virtual ~IArgValueParser() = default;

		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const = 0;
		virtual std::string typeName() const = 0;
	};
}
