#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "controller/commands/ACommand.h"
#include "controller/factories/ACommandFactory.h"
#include "controller/parsing/Tokenizer.h"

#include <memory>
#include <unordered_map>
#include <string>

class CommandRegistry
{
public:
	static CommandRegistry& instance();
	std::shared_ptr<ACommandFactory> getFactory(const std::string& name) const;
	void registerFactory(const std::string& name, std::shared_ptr<ACommandFactory> factory);
private:
	CommandRegistry() = default;
	CommandRegistry(const CommandRegistry&) = delete;
	CommandRegistry(CommandRegistry&&) noexcept = delete;
	CommandRegistry& operator=(const CommandRegistry&) = delete;
	CommandRegistry& operator=(CommandRegistry&&) noexcept = delete;
private:
	std::unordered_map<std::string, std::shared_ptr<ACommandFactory>> m_factories;
};

void registerMainCommands(AppContext& context, IViewer& viewer);
