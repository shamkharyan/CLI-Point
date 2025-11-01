//#pragma once
//
//#include "model/Shape.h"
//#include "core/actions/AAction.h"
//#include "model/utils/Color.h"
//
//#include <optional>
//
//namespace ppt::core::act
//{
//  class AddShapeAction : public AAction
//  {
//  public:
//    AddShapeAction(model::Shape::Type type, model::utils::BBox bbox, model::utils::Properties properties) :
//      m_type(type),
//      m_bbox(bbox),
//      m_properties(properties)
//    {}
//
//    bool doAction() override;
//    bool undoAction() override;
//  private:
//    model::Shape::Type m_type;
//    model::utils::BBox m_bbox;
//    model::utils::Properties m_properties;
//  };
//}
