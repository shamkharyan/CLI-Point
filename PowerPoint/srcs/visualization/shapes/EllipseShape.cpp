#include "visualization/shapes/EllipseShape.h"

using namespace ppt::vis;

EllipseShape::EllipseShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void EllipseShape::draw(IRenderer& renderer) const
{
    float x = m_shapeData.geometry.topLeft.x;
    float y = m_shapeData.geometry.topLeft.y;
    float w = m_shapeData.geometry.size.x;
    float h = m_shapeData.geometry.size.y;

    float cx = x + w / 2.0f;
    float cy = y + h / 2.0f;
    float rx = w / 2.0f;
    float ry = h / 2.0f;

    constexpr float k = 0.552284749831f;

    float ox = rx * k;
    float oy = ry * k;

    Path path;

    // start at right middle
    path.moveTo(cx + rx, cy);

    // top-right
    path.cubicTo(
        cx + rx, cy - oy,
        cx + ox, cy - ry,
        cx, cy - ry
    );

    // top-left
    path.cubicTo(
        cx - ox, cy - ry,
        cx - rx, cy - oy,
        cx - rx, cy
    );

    // bottom-left
    path.cubicTo(
        cx - rx, cy + oy,
        cx - ox, cy + ry,
        cx, cy + ry
    );

    // bottom-right
    path.cubicTo(
        cx + ox, cy + ry,
        cx + rx, cy + oy,
        cx + rx, cy
    );

    path.close();

    Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
    Brush brush{ m_shapeData.style.fillColor };

    renderer.drawPath(path, pen, brush);
}
