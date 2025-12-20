#pragma once

#include "visualization/shapes/IShape.h"

namespace ppt::vis
{
	class RectangleShape : public IShape
	{
	public:
		RectangleShape(const model::ShapeData& shapeData);

		void draw(IRenderer& renderer) const override;
	private:
		const model::ShapeData& m_shapeData;
	};
}
