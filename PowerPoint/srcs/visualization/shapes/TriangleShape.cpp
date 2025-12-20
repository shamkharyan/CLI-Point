#include "visualization/shapes/TriangleShape.h"

using namespace ppt::vis;

TriangleShape::TriangleShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void TriangleShape::draw(IRenderer& renderer) const
{
    float x = m_shapeData.geometry.topLeft.x;
    float y = m_shapeData.geometry.topLeft.y;
    float width = m_shapeData.geometry.size.x;
    float height = m_shapeData.geometry.size.y;

    float x0 = x + width / 2.0f;
    float y0 = y;
    float x1 = x;                 
    float y1 = y + height;
    float x2 = x + width;         
    float y2 = y + height;

    Path path;
    path.moveTo(x0, y0);
    path.lineTo(x1, y1);
    path.lineTo(x2, y2);
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