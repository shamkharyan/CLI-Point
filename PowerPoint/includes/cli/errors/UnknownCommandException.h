#pragma once

#include <stdexcept>

namespace ppt::cli::err
{
  class UnknownCommandException : public std::runtime_error
  {
  public:
    explicit UnknownCommandException(const std::string& cmd)
      : std::runtime_error("Unknown command: " + cmd) {}
  };
}


