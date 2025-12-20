#pragma once

#include "IShapeFactory.h"
#include "visualization/shapes/TriangleShape.h"

namespace ppt::vis
{
	class TriangleShapeFactory : public IShapeFactory
	{
	public:
		std::unique_ptr<IShape> create(const model::ShapeData& data) const override
		{
			return std::make_unique<TriangleShape>(data);
		}
	};
}
