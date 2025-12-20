#include "visualization/shapes/RectangleShape.h"

using namespace ppt::vis;

RectangleShape::RectangleShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void RectangleShape::draw(IRenderer& renderer) const
{
	Path path;
	float x = m_shapeData.geometry.topLeft.x;
	float y = m_shapeData.geometry.topLeft.y;
	float width = m_shapeData.geometry.size.x;
	float height = m_shapeData.geometry.size.y;

	path.moveTo(x, y);
	path.lineTo(x + width, y);
	path.lineTo(x + width, y + height);
	path.lineTo(x, y + height);
	path.close();

	Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
	Brush brush{ m_shapeData.style.fillColor };

	renderer.drawPath(path, pen, brush);

	if (!m_shapeData.text.empty())
	{
		float textX = x + width / 2.0f;
		float textY = y + height / 2.0f;

		renderer.drawText(m_shapeData.text, textX, textY, m_shapeData.textStyle);
	}
}