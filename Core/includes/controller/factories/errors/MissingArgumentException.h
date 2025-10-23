#pragma once

#include <stdexcept>

class MissingArgumentException : public std::runtime_error
{
public:
  explicit MissingArgumentException(const std::string& arg)
    : std::runtime_error("Missing argument: " + arg) {}
};

