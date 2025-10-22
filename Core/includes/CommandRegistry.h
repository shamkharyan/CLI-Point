#pragma once

#include "model/commands/ACommand.h"
#include "model/AppContext.h"
#include "controller/parsing/Tokenizer.h"

#include <memory>
#include <functional>
#include <unordered_map>
#include <string>

using CommandFactory = std::function<std::unique_ptr<ACommand>(Tokenizer&, AppContext&)>;

class CommandRegistry
{
public:
	static CommandRegistry& instance();
	CommandFactory getFactory(const std::string& name) const;
	void registerCommand(const std::string& name, CommandFactory factory);

	bool findCommand(const std::string& name) const;

private:
	CommandRegistry() = default;
	CommandRegistry(const CommandRegistry&) = delete;
	CommandRegistry(CommandRegistry&&) noexcept = delete;
	CommandRegistry& operator=(const CommandRegistry&) = delete;
	CommandRegistry& operator=(CommandRegistry&&) noexcept = delete;
private:
	std::unordered_map<std::string, CommandFactory> m_factories;
};

void registerMainCommands();
