#pragma once

#include <stdexcept>
#include <string>

namespace ppt::cli
{
    class ExecutionError : public std::runtime_error {
    public:
        explicit ExecutionError(const std::string& msg)
            : std::runtime_error("Execution error: " + msg) {}
    };
}
