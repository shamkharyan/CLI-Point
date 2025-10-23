#pragma once

#include <stdexcept>

class InvalidArgumentValueException : public std::runtime_error
{
public:
  explicit InvalidArgumentValueException(const std::string& arg)
    : std::runtime_error("Invalid argument value: " + arg) {}
};

