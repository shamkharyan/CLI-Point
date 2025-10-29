#pragma once

#include "core/actions/IAction.h"
#include "model/utils/Color.h"
#include "model/Slide.h"
#include "model/utils/Color.h"

#include <optional>
#include <memory>

namespace ppt::core::act
{
  class RemoveSlideAction : public IAction
  {
  public:
    RemoveSlideAction(std::optional<std::size_t> at) : m_at(at) {}

    void doAction() override;
    void undoAction() override;
  private:
    std::optional<model::Slide> m_oldSlide;
    std::optional<std::size_t> m_at;
  };
}
