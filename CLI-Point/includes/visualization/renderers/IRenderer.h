#pragma once

#include <string>
#include <vector>
#include <utility>

#include "visualization/utils/Path.h"
#include "visualization/utils/Pen.h"
#include "visualization/utils/Brush.h"

#include "model/utils/TextStyle.h"
#include "model/utils/GeometryData.h"

namespace ppt::vis
{
    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;

        virtual void beginDraw() = 0;
		virtual void endDraw() = 0;

		virtual void drawPath(const Path& path, const Pen& pen, const Brush& brush) = 0;

        virtual void drawText(
            const std::string& text,
            const model::utils::GeometryData& geometry,
            const model::utils::TextStyle& style
        ) = 0;

        virtual void clear(const model::utils::Color& color) = 0;
    };
}
