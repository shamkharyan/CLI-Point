#pragma once

#include "core/actions/IAction.h"
#include "model/utils/Color.h"

#include <optional>

namespace ppt::core::act
{
  class AddSlideAction : public IAction
  {
  public:
    AddSlideAction(std::optional<std::size_t> at, model::utils::Color bgColor) :
      m_at(at),
      m_bgColor(bgColor) {}

    void doAction() override;
    void undoAction() override;
  private:
    std::optional<std::size_t> m_at;
    model::utils::Color m_bgColor;
  };
}
