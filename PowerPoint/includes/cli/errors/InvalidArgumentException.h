#pragma once

#include <stdexcept>

namespace ppt::cli::err
{
  class InvalidArgumentException : public std::runtime_error
  {
  public:
    explicit InvalidArgumentException(const std::string& arg)
      : std::runtime_error("Invalid argument: " + arg) {}
  };
}
