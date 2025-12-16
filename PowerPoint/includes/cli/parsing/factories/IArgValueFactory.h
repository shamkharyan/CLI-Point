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

		virtual bool canCreate(const std::vector<std::string>& argValue) const = 0;
		virtual ArgValue create(const std::vector<std::string>& argValue) const = 0;
		virtual std::string typeName() const = 0;
	};
}
