#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/meta/ArgumentMeta.h"

#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>

namespace ppt::cli::meta
{
	class CommandMeta
	{
	public:
		using container = std::vector<ArgumentMeta>;
		using alias_container = std::unordered_map<std::string, const ArgumentMeta*>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		CommandMeta(
			const std::string& name,
			const std::string& description,
			const std::shared_ptr<factories::ICommandFactory>& factory
		);

		const std::string& getName() const noexcept { return m_name; }
		const std::string& getDescription() const noexcept { return m_description; }
		std::shared_ptr<factories::ICommandFactory> getFactory() const noexcept { return m_factory; }

		const ArgumentMeta* getArgumentMeta(const std::string& argName) const;
		void registerArgumentMeta(ArgumentMeta argMeta);

		iterator begin() noexcept { return m_argMetas.begin(); }
		iterator end() noexcept { return m_argMetas.end(); }

		const_iterator begin() const noexcept { return m_argMetas.begin(); }
		const_iterator end() const noexcept { return m_argMetas.end(); }

		const_iterator cbegin() const noexcept { return m_argMetas.cbegin(); }
		const_iterator cend() const noexcept { return m_argMetas.cend(); }

	private:
		std::string m_name;
		std::string m_description;
		std::shared_ptr<factories::ICommandFactory> m_factory;
		container m_argMetas;

		alias_container m_aliasIndexes;
	};
}
