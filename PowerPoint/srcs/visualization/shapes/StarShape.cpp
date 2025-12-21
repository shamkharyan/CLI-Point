#include "visualization/shapes/StarShape.h"

#include <cmath>

using namespace ppt::vis;

namespace
{
    constexpr float kPi = 3.14159265f;
    constexpr float kHalfPi = kPi / 2.0f;
    constexpr int kMinStarPoints = 3;
    constexpr float kDefaultInnerRatio = 0.5f;
    constexpr int kDefaultNumPoints = 5;
}

StarShape::StarShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void StarShape::draw(IRenderer& renderer) const
{
    float x = m_shapeData.geometry.x;
    float y = m_shapeData.geometry.y;
    float w = m_shapeData.geometry.width;
    float h = m_shapeData.geometry.height;

    float innerRatio = m_shapeData.adjustments[0];
    int numPoints = m_shapeData.adjustments[1];

    float centerX = x + w / 2.0f;
    float centerY = y + h / 2.0f;

    float outerRx = w / 2.0f;
    float outerRy = h / 2.0f;
    float innerRx = outerRx * innerRatio;
    float innerRy = outerRy * innerRatio;

    Path path;
    int totalVertices = numPoints * 2;
    float angleStep = (2.0f * kPi) / totalVertices;
    float startAngle = -kHalfPi;

    for (int i = 0; i < totalVertices; ++i)
    {
        float currentAngle = startAngle + i * angleStep;
        float rx = (i % 2 == 0) ? outerRx : innerRx;
        float ry = (i % 2 == 0) ? outerRy : innerRy;

        float px = centerX + std::cos(currentAngle) * rx;
        float py = centerY + std::sin(currentAngle) * ry;

        if (i == 0)
            path.moveTo(px, py);
        else
            path.lineTo(px, py);
    }
    path.close();

    Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
    Brush brush{ m_shapeData.style.fillColor };

    renderer.drawPath(path, pen, brush);

    if (!m_shapeData.text.empty())
        renderer.drawText(m_shapeData.text, m_shapeData.geometry, m_shapeData.textStyle);
}
