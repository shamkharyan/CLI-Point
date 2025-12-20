#include "visualization/shapes/EllipseShape.h"

using namespace ppt::vis;

EllipseShape::EllipseShape(const model::ShapeData& shapeData) : m_shapeData(shapeData) {}

void EllipseShape::draw(IRenderer& renderer) const
{
	// Center and radii
    float cx = m_shapeData.geometry.topLeft.x + m_shapeData.geometry.size.x / 2.0f;
    float cy = m_shapeData.geometry.topLeft.y + m_shapeData.geometry.size.y / 2.0f;
    float rx = m_shapeData.geometry.size.x / 2.0f;
    float ry = m_shapeData.geometry.size.y / 2.0f;

	// Approximate ellipse using 4 cubic Bezier curves
	const float k = 0.552284749831f; // Approximation constant
    float ox = rx * k;
    float oy = ry * k;

    Path path;
	path.moveTo(cx + rx, cy); // rightmost point

	// upper right quarter
    path.cubicTo(cx + rx, cy - oy, cx + ox, cy - ry, cx, cy - ry);

	// upper left quarter
    path.cubicTo(cx - ox, cy - ry, cx - rx, cy - oy, cx - rx, cy);

	// downer left quarter
    path.cubicTo(cx - rx, cy + oy, cx - ox, cy + ry, cx, cy + ry);

	// downer right quarter
    path.cubicTo(cx + ox, cy + ry, cx + rx, cy + oy, cx + rx, cy);

    path.close();

	// Style
    Pen pen{ m_shapeData.style.outlineColor, m_shapeData.style.outlineWidth };
    Brush brush{ m_shapeData.style.fillColor };

    // Render
    renderer.drawPath(path, pen, brush);
}