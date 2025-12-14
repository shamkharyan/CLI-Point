#pragma once

#include "ArgValue.h"

#include <vector>
#include <string>

namespace ppt::cli
{
	class IArgValueFactory
	{
	public:
		virtual ~IArgValueFactory() = default;

		virtual bool canParse(const std::vector<std::string>& argValue) const = 0;
		virtual ArgValue parse(const std::vector<std::string>& argValue) const = 0;
		virtual std::string description() const = 0;
	};
}
