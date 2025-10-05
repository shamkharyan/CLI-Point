#pragma once

#include "AllCommands.h"
#include "Tokenizer.h"

#include <string>
#include <unordered_set>
#include <istream>
#include <optional>
#include <memory>

class Parser
{
public:
    bool evalToken(const std::string& token);
    static std::optional<Command> parse(std::istream& in);
private:
    static std::unique_ptr<Command> createCommand(const std::string& command);
    void initCommands();
private:
    enum class State
    {
        EMPTY,
        ARGUMENT,
        VALUE,
        ERROR,
        END
    };

    State m_state = State::EMPTY;
    std::unordered_set<Command> m_commands;
    std::string m_currCommand;
    Tokenizer m_tok;
};
