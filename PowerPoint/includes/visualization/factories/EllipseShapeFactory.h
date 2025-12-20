#pragma once

#include "IShapeFactory.h"
#include "visualization/shapes/EllipseShape.h"

namespace ppt::vis
{
	class EllipseShapeFactory : public IShapeFactory
	{
	public:
		std::unique_ptr<IShape> create(const model::ShapeData& data) const override
		{
			return std::make_unique<EllipseShape>(data);
		}
	};
}
