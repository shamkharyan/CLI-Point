#pragma once

#include <stdexcept>

class UnknownCommandException : public std::runtime_error
{
public:
  explicit UnknownCommandException(const std::string& cmd)
    : std::runtime_error("Unknown command: " + cmd) {}
};


