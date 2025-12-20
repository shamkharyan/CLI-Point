#pragma once

#include "visualization/renderers/IRenderer.h"
#include "model/ShapeData.h"

namespace ppt::vis
{
    class IShape
    {
    public:
        virtual ~IShape() = default;
        virtual void draw(IRenderer& renderer) const = 0;
    };
}
