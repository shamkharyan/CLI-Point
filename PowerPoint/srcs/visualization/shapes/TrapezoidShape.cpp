#include "visualization/shapes/TrapezoidShape.h"

using namespace ppt::vis;

namespace
{
    constexpr float kDefaultTopRatio = 0.6f;
}

TrapezoidShape::TrapezoidShape(const model::ShapeData& shapeData)
    : m_shapeData(shapeData)
{
}

void TrapezoidShape::draw(IRenderer& renderer) const
{
    float x = m_shapeData.geometry.x;
    float y = m_shapeData.geometry.y;
    float w = m_shapeData.geometry.width;
    float h = m_shapeData.geometry.height;

    float topRatio = m_shapeData.adjustments[0];

    float topWidth = w * topRatio;
    float delta = (w - topWidth) / 2.0f;

    Path path;
    path.moveTo(x + delta, y);
    path.lineTo(x + delta + topWidth, y);
    path.lineTo(x + w, y + h);
    path.lineTo(x, y + h);
    path.close();

    Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
    Brush brush{ m_shapeData.style.fillColor };
    renderer.drawPath(path, pen, brush);

    if (!m_shapeData.text.empty())
    {
        float textX = x + w / 2.0f;
        float textY = y + h / 2.0f;
        renderer.drawText(m_shapeData.text, m_shapeData.geometry, m_shapeData.textStyle);
    }
}
