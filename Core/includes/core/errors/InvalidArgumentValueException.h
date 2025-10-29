#pragma once

#include <stdexcept>

namespace ppt::core::err
{
  class InvalidArgumentValueException : public std::runtime_error
  {
  public:
    explicit InvalidArgumentValueException(const std::string& arg)
      : std::runtime_error("Invalid argument value: " + arg) {}
  };
}

