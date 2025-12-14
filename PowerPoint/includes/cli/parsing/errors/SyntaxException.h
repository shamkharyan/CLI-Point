#pragma once

#include <stdexcept>
#include <string>

namespace ppt::cli 
{
    class SyntaxException : public std::runtime_error {
    public:
        explicit SyntaxException(const std::string& msg)
            : std::runtime_error("Syntax error: " + msg) {}
    };
}
