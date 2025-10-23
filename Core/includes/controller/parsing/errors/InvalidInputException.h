#pragma once

#include <stdexcept>

class InvalidInputException : public std::runtime_error
{
public:
  explicit InvalidInputException(const std::string& input)
    : std::runtime_error("Invalid input: " + input) {}
};