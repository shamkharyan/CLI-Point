#pragma once

#include "controller/commands/ACommand.h"
#include "model/AppContext.h"

#include <memory>
#include <unordered_map>
#include <vector>

using Arguments = std::unordered_map<std::string, std::vector<std::string>>;

class ACommandFactory
{
public:
  ACommandFactory(AppContext& context) : m_context(context) {}
  virtual std::unique_ptr<ACommand> createCommand(const Arguments& args) = 0;
protected:
  AppContext& m_context;
};
