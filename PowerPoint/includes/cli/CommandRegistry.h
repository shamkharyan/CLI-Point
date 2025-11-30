#pragma once

#include "cli/meta/CommandMeta.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace ppt::cli
{
	class CommandRegistry
	{
	public:
		std::shared_ptr<factories::ICommandFactory> getFactory(const std::string& name) const
		{
			if (auto meta = getMeta(name))
				return meta->getFactory();
		}

		std::shared_ptr<meta::CommandMeta> getMeta(const std::string& name) const
		{
			auto it = m_commands.find(name);
			if (it == m_commands.end())
				return nullptr;
			return it->second;
		}

		void registerMeta(const std::string& name, std::shared_ptr<meta::CommandMeta> command)
		{
			m_commands[name] = std::move(command);
		}

		void unregisterMeta(const std::string& name)
		{
			m_commands.erase(name);
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<meta::CommandMeta>> m_commands;
	};
}
