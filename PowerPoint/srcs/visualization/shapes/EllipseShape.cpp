#include "visualization/shapes/EllipseShape.h"

using namespace ppt::vis;

void EllipseleShape::draw(IRenderer& renderer, const model::ShapeData& shapeData) const
{
	// Center and radii
    float cx = shapeData.geometry.topLeft.x + shapeData.geometry.size.x / 2.0f;
    float cy = shapeData.geometry.topLeft.y + shapeData.geometry.size.y / 2.0f;
    float rx = shapeData.geometry.size.x / 2.0f;
    float ry = shapeData.geometry.size.y / 2.0f;

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
    Pen pen{ shapeData.style.outlineColor, shapeData.style.outlineWidth };
    Brush brush{ shapeData.style.fillColor };

    // Render
    renderer.drawPath(path, pen, brush);
}