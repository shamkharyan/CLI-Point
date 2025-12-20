#pragma once

#include <string>
#include <vector>
#include <utility>

#include "visualization/utils/Path.h"
#include "visualization/utils/Pen.h"
#include "visualization/utils/Brush.h"

namespace ppt::vis
{
    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void beginDraw() = 0;
		virtual void endDraw() = 0;

		virtual void drawPath(const Path& path, const Pen& pen, const Brush& brush) = 0;
    };
}
