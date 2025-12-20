#pragma once

#include "visualization/shapes/IShape.h"

namespace ppt::vis
{
	class RectangleShape : public IShape
	{
	public:
		void draw(IRenderer& renderer, const model::ShapeData& shapeData) const override;
	};
}
