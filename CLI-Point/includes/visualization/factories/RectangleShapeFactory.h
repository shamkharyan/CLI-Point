#pragma once

#include "IShapeFactory.h"
#include "visualization/shapes/RectangleShape.h"

namespace ppt::vis
{
	class RectangleShapeFactory : public IShapeFactory
	{
	public:
		std::unique_ptr<IShape> create(const model::ShapeData& data) const override
		{
			return std::make_unique<RectangleShape>(data);
		}
	};
}
