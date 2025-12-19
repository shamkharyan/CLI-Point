#pragma once

#pragma once

#include "IArgValueFactory.h"

namespace ppt::cli
{
	class ColorRGBFactory : public IArgValueFactory	
	{
	public:
		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;
	};
}
