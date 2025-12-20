#pragma once

#include "visualization/shapes/IShape.h"

namespace ppt::vis
{
	class EllipseShape : public IShape
	{
	public:
		EllipseShape(const model::ShapeData& shapeData);

		void draw(IRenderer& renderer) const override;
	private:
		const model::ShapeData& m_shapeData;
	};
}
