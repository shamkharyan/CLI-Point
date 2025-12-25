#include "visualization/utils/Path.h"

using namespace ppt::vis;


void Path::moveTo(float x, float y)
{
	m_commands.push_back({ PathCommand::Type::MoveTo, {x,y} });
}

void Path::lineTo(float x, float y)
{
	m_commands.push_back({ PathCommand::Type::LineTo, {x,y} });
}

void Path::quadTo(float cx, float cy, float x, float y)
{
    m_commands.push_back({
        PathCommand::Type::QuadTo,
        {cx, cy},  // control
        {x,  y}    // end
        });
}

void Path::cubicTo(float cx1, float cy1,
    float cx2, float cy2,
    float x, float y)
{
    m_commands.push_back({
        PathCommand::Type::CubicTo,
        {cx1, cy1},  // control point 1
        {cx2, cy2},  // control point 2
        {x,  y}      // end point
        });
}

void Path::close()
{
	m_commands.push_back({ PathCommand::Type::Close });
}
