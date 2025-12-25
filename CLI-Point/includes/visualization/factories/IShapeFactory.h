#pragma once

#include "visualization/shapes/IShape.h"
#include "model/ShapeData.h"
#include <memory>

namespace ppt::vis
{
	class IShapeFactory
	{
	public:
		virtual ~IShapeFactory() = default;
		virtual std::unique_ptr<IShape> create(const model::ShapeData& data) const = 0;
	};
}
