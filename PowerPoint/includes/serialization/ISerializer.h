#pragma once

#include "model/Presentation.h"

#include <string>

namespace ppt::serialization
{
	class ISerializer
	{
	public:
		virtual ~ISerializer() = default;
		virtual void serialize(const model::Presentation& presentation, const std::string& filePath) const = 0;
	};
}
