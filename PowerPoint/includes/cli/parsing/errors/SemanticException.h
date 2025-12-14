#pragma once

#include <stdexcept>
#include <string>

namespace ppt::cli
{
    class SemanticException : public std::runtime_error {
    public:
        explicit SemanticException(const std::string& msg)
            : std::runtime_error("Semantic error: " + msg) {}
    };
}
