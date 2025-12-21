#pragma once

#include "visualization/shapes/IShape.h"

namespace ppt::vis
{
	class StarShape : public IShape
	{
	public:
		explicit StarShape(const model::ShapeData& shapeData);

		void draw(IRenderer& renderer) const override;
	private:
		const model::ShapeData& m_shapeData;
	};
}
