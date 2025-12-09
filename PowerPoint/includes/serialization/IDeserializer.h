#pragma once

#include "model/Presentation.h"

#include <string>

namespace ppt::serialization
{
	class IDeserializer
	{
	public:
		virtual ~IDeserializer() = default;
		virtual void deserialize(model::Presentation& presentation, const std::string& filePath) const = 0;
	};
}
