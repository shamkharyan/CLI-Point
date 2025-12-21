#pragma once

#include "IShapeFactory.h"
#include "visualization/shapes/StarShape.h"

namespace ppt::vis
{
	class StarShapeFactory : public IShapeFactory
	{
	public:
		std::unique_ptr<IShape> create(const model::ShapeData& data) const override
		{
			return std::make_unique<StarShape>(data);
		}
	};
}
