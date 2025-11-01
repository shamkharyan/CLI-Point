#pragma once

#include "model/Shape.h"
#include "core/actions/AAction.h"
#include "model/utils/ShapeType.h"

#include <optional>

namespace ppt::core::act
{
    class ReplaceShapeAction : public AAction
    {
    public:
        ReplaceShapeAction(std::size_t shapeId, model::utils::ShapeType type, std::optional<std::size_t> at);

        bool doAction() override;
        bool undoAction() override;
    private:
        std::size_t m_shapeId;
        model::utils::ShapeType m_type;
        std::optional<std::size_t> m_at;

        std::optional<model::utils::ShapeType> m_oldType = std::nullopt;
    };
}
