#pragma once

#include <stdexcept>
#include <string>

namespace ppt::core
{
    class ActionException : public std::runtime_error {
    public:
        explicit ActionException(const std::string& msg)
            : std::runtime_error("Action error: " + msg) {}
    };
}
