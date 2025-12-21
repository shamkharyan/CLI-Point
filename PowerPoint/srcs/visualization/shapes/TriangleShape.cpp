#include "visualization/shapes/TriangleShape.h"

using namespace ppt::vis;

TriangleShape::TriangleShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void TriangleShape::draw(IRenderer& renderer) const
{
    float x = m_shapeData.geometry.x;
    float y = m_shapeData.geometry.y;
    float w = m_shapeData.geometry.width;
    float h = m_shapeData.geometry.height;

    float x0 = x + w / 2.0f;
    float y0 = y;
    float x1 = x;                 
    float y1 = y + h;
    float x2 = x + w;         
    float y2 = y + h;

    Path path;
    path.moveTo(x0, y0);
    path.lineTo(x1, y1);
    path.lineTo(x2, y2);
    path.close();

    Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
    Brush brush{ m_shapeData.style.fillColor };

    renderer.drawPath(path, pen, brush);

    if (!m_shapeData.text.empty())
        renderer.drawText(m_shapeData.text, m_shapeData.geometry, m_shapeData.textStyle);
}