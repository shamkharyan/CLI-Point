#pragma once

#include "model/Slide.h"

#include <string>

namespace ppt::ser
{
	class IExporter
	{
	public:
		virtual ~IExporter() = default;
		virtual void exportSlide(const model::Slide& slide, const std::string& filePath) const = 0;
	};
}
