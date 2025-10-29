#pragma once

namespace ppt::core::act
{
  class IAction
  {
  public:
    virtual void doAction() = 0;
    virtual void undoAction() = 0;
    virtual ~IAction() = default;
  };
}
