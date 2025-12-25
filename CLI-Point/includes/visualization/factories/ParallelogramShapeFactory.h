#pragma once

#include "IShapeFactory.h"
#include "visualization/shapes/ParallelogramShape.h"

namespace ppt::vis
{
	class ParallelogramShapeFactory : public IShapeFactory
	{
	public:
		std::unique_ptr<IShape> create(const model::ShapeData& data) const override
		{
			return std::make_unique<ParallelogramShape>(data);
		}
	};
}
