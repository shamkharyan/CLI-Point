#include "visualization/shapes/ParallelogramShape.h"

using namespace ppt::vis;

namespace
{
    constexpr float kDefaultSkewRatio = 0.3f; // сдвиг верхней стороны относительно нижней
}

ParallelogramShape::ParallelogramShape(const model::ShapeData& shapeData)
    : m_shapeData(shapeData)
{
}

void ParallelogramShape::draw(IRenderer& renderer) const
{
    float x = m_shapeData.geometry.x;
    float y = m_shapeData.geometry.y;
    float w = m_shapeData.geometry.width;
    float h = m_shapeData.geometry.height;

    const auto& adj = m_shapeData.adjustments;
    float skewRatio = (adj.size() > 0) ? adj[0] : kDefaultSkewRatio;
    if (skewRatio < 0.0f) skewRatio = 0.0f;
    if (skewRatio > 1.0f) skewRatio = 1.0f;

    float skewX = w * skewRatio;

    Path path;
    path.moveTo(x + skewX, y);
    path.lineTo(x + w + skewX, y);
    path.lineTo(x + w, y + h);
    path.lineTo(x, y + h);
    path.close();

    Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
    Brush brush{ m_shapeData.style.fillColor };
    renderer.drawPath(path, pen, brush);

    if (!m_shapeData.text.empty())
        renderer.drawText(m_shapeData.text, m_shapeData.geometry, m_shapeData.textStyle);
}
