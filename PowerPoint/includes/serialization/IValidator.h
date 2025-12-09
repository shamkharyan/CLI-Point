#pragma once

#include <string>

namespace ppt::serialization
{
	class IValidator
	{
	public:
		virtual ~IValidator() = default;
		virtual bool validate(const std::string& filePath) const = 0;
	};
}