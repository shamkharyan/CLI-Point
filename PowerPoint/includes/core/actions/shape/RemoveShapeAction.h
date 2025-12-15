//#pragma once
//
//#include "model/Shape.h"
//#include "core/actions/AAction.h"
//
//#include <optional>
//
//namespace ppt::core::act
//{
//    class RemoveShapeAction : public AAction
//    {
//    public:
//        RemoveShapeAction(std::size_t shapeId, std::optional<std::size_t> at);
//
//        bool doAction() override;
//        bool undoAction() override;
//    private:
//        std::size_t m_shapeId;
//        model::utils::Coord m_position;
//        std::optional<std::size_t> m_at;
//
//        std::optional<model::Shape> m_oldShape = std::nullopt;
//    };
//}
