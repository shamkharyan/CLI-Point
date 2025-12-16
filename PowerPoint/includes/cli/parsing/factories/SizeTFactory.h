#pragma once

#include "IArgValueFactory.h"

namespace ppt::cli
{
	class SizeTFactory : public IArgValueFactory
	{
	public:
		virtual bool canCreate(const std::vector<std::string>& argValue) const override;
		virtual ArgValue create(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;
	};
}