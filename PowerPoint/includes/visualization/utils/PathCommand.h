#pragma once

#include "visualization/utils/Point.h"

namespace ppt::vis
{
    struct PathCommand
    {
        enum class Type
        {
            MoveTo,
            LineTo,
            QuadTo,    
            CubicTo,   
            Close
        };

        Type type;

        Point p1;
        Point p2;
        Point p3;
    };
}