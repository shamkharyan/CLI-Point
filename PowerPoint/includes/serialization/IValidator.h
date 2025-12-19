#pragma once

#include <string>

namespace ppt::ser
{
	class IValidator
	{
	public:
		virtual ~IValidator() = default;
		virtual bool validate(const std::string& filePath) const = 0;
	};
}