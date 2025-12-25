#pragma once

#include "IShapeFactory.h"
#include "visualization/shapes/TrapezoidShape.h"

namespace ppt::vis
{
	class TrapezoidShapeFactory : public IShapeFactory
	{
	public:
		std::unique_ptr<IShape> create(const model::ShapeData& data) const override
		{
			return std::make_unique<TrapezoidShape>(data);
		}
	};
}
