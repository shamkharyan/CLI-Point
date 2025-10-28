#pragma once

#include "core/commands/ICommand.h"

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>

namespace ppt::cli::factories
{
    using Arguments = std::unordered_map<std::string, std::vector<std::string>>;

    class ICommandFactory
    {
    public:
        virtual ~ICommandFactory() = default;
        virtual std::unique_ptr<core::cmds::ICommand> createCommand(const Arguments& args) = 0;
    };
}
