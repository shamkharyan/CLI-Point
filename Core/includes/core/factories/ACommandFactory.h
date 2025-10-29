#pragma once

#include "core/commands/ACommand.h"
#include "model/AppContext.h"

#include <memory>
#include <unordered_map>
#include <vector>

namespace ppt::core::factories
{
  using Arguments = std::unordered_map<std::string, std::vector<std::string>>;

  class ACommandFactory
  {
  public:
    ACommandFactory(model::AppContext& context) : m_context(context) {}
    virtual std::unique_ptr<cmds::ACommand> createCommand(const Arguments& args) = 0;
  protected:
    model::AppContext& m_context;
  };
}
