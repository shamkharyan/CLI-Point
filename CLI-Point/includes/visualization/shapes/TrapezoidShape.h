#pragma once

#include "visualization/shapes/IShape.h"
#include "model/ShapeData.h"
#include "visualization/renderers/IRenderer.h"

namespace ppt::vis
{
    class TrapezoidShape : public IShape
    {
    public:
        explicit TrapezoidShape(const model::ShapeData& shapeData);
        void draw(IRenderer& renderer) const override;

    private:
        model::ShapeData m_shapeData;
    };
}
