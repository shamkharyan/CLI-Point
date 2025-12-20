#include "visualization/shapes/TriangleShape.h"

using namespace ppt::vis;

void TriangleShape::draw(IRenderer& renderer, const model::ShapeData& shapeData) const
{
    float x = shapeData.geometry.topLeft.x;
    float y = shapeData.geometry.topLeft.y;
    float width = shapeData.geometry.size.x;
    float height = shapeData.geometry.size.y;

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

    Pen pen{ shapeData.style.outlineColor, shapeData.style.outlineWidth };
    Brush brush{ shapeData.style.fillColor };

    renderer.drawPath(path, pen, brush);
}