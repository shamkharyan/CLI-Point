#pragma once

#pragma once

#include "IArgValueFactory.h"

namespace ppt::cli
{
	class BoolFactory : public IArgValueFactory
	{
	public:
		virtual bool canParse(const std::vector<std::string>& argValue) const override;
		virtual ArgValue parse(const std::vector<std::string>& argValue) const override;
		virtual std::string description() const override;
	};
}
