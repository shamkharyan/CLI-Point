#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/ACommand.h"
#include "core/factories/ACommandFactory.h"

#include <memory>
#include <unordered_map>
#include <string>

namespace ppt::core
{
	class CommandRegistry
	{
	public:
		static CommandRegistry& instance();
		std::shared_ptr<factories::ACommandFactory> getFactory(const std::string& name) const;
		void registerFactory(const std::string& name, std::shared_ptr<factories::ACommandFactory> factory);
	private:
		CommandRegistry() = default;
		CommandRegistry(const CommandRegistry&) = delete;
		CommandRegistry(CommandRegistry&&) noexcept = delete;
		CommandRegistry& operator=(const CommandRegistry&) = delete;
		CommandRegistry& operator=(CommandRegistry&&) noexcept = delete;
	private:
		std::unordered_map<std::string, std::shared_ptr<factories::ACommandFactory>> m_factories;
	};
}
