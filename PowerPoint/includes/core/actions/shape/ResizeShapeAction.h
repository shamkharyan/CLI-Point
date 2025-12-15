//#pragma once
//
//#include "model/Shape.h"
//#include "core/actions/AAction.h"
//#include "model/utils/Coord.h"
//
//#include <optional>
//
//namespace ppt::core::act
//{
//    class ResizeShapeAction : public AAction
//    {
//    public:
//        ResizeShapeAction(std::size_t shapeId, model::utils::Coord size, std::optional<std::size_t> at);
//
//        bool doAction() override;
//        bool undoAction() override;
//    private:
//        std::size_t m_shapeId;
//        model::utils::Coord m_size;
//        std::optional<std::size_t> m_at;
//
//        std::optional<model::utils::Coord> m_oldSize = std::nullopt;
//    };
//}
