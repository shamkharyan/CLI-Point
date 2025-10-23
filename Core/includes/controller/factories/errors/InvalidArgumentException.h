#pragma once

#include <stdexcept>

class InvalidArgumentException : public std::runtime_error
{
public:
  explicit InvalidArgumentException(const std::string& arg)
    : std::runtime_error("Invalid argument: " + arg) {}
};
