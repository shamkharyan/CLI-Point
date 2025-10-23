#pragma once

#include <stdexcept>

class MissingArgumentValueException : public std::runtime_error
{
public:
  explicit MissingArgumentValueException(const std::string& arg)
    : std::runtime_error("Missing argument values for: " + arg) {}
};


