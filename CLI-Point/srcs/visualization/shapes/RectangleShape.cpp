#include "visualization/shapes/RectangleShape.h"

using namespace ppt::vis;

RectangleShape::RectangleShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void RectangleShape::draw(IRenderer& renderer) const
{
	float x = m_shapeData.geometry.x;
	float y = m_shapeData.geometry.y;
	float w = m_shapeData.geometry.width;
	float h = m_shapeData.geometry.height;

	Path path;
	path.moveTo(x, y);
	path.lineTo(x + w, y);
	path.lineTo(x + w, y + h);
	path.lineTo(x, y + h);
	path.close();

	Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
	Brush brush{ m_shapeData.style.fillColor };

	renderer.drawPath(path, pen, brush);

	if (!m_shapeData.text.empty())
		renderer.drawText(m_shapeData.text, m_shapeData.geometry, m_shapeData.textStyle);
}