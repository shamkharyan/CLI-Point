#include "visualization/shapes/RectangleShape.h"

using namespace ppt::vis;

void RectangleShape::draw(IRenderer& renderer, const model::ShapeData& shapeData) const
{
	Path path;
	float x = shapeData.geometry.topLeft.x;
	float y = shapeData.geometry.topLeft.y;
	float width = shapeData.geometry.size.x;
	float height = shapeData.geometry.size.y;

	path.moveTo(x, y);
	path.lineTo(x + width, y);
	path.lineTo(x + width, y + height);
	path.lineTo(x, y + height);
	path.close();

	Pen pen{ shapeData.style.outlineColor, shapeData.style.outlineWidth };
	Brush brush{ shapeData.style.fillColor };

	renderer.drawPath(path, pen, brush);
}