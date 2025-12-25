#pragma once

#pragma once

#include "IArgValueParser.h"

namespace ppt::cli
{
	class BoolParser : public IArgValueParser
	{
	public:
		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;
	};
}
