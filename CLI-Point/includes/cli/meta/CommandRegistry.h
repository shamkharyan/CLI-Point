#pragma once

#include "cli/meta/CommandMeta.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace ppt::cli
{
	class CommandRegistry
	{
	public:
		using container = std::vector<meta::CommandMeta>;
		using alias_container = std::unordered_map<std::string, std::size_t>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		const meta::CommandMeta* getCommandMeta(const std::string& name) const noexcept;
		void registerCommandMeta(meta::CommandMeta cmdMeta);

		iterator begin() noexcept { return m_commands.begin(); }
		iterator end() noexcept { return m_commands.end(); }

		const_iterator begin() const noexcept { return m_commands.begin(); }
		const_iterator end() const noexcept { return m_commands.end(); }

		const_iterator cbegin() const noexcept { return m_commands.cbegin(); }
		const_iterator cend() const noexcept { return m_commands.cend(); }

	private:
		container m_commands;

		alias_container m_aliasIndexes;
	};
}
