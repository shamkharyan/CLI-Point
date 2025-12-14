#pragma once

#include "cli/parsing/IArgValueFactory.h"
#include "cli/parsing/ArgValue.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

namespace ppt::cli::meta
{
	class ArgumentMeta
	{
	public:
		ArgumentMeta(
			const std::string canonicalName,
			const std::string& description,
			bool isRequired,
			const std::vector<std::string>& defaultValues
		);

		const std::string& getCanonicalName() const noexcept { return m_canonicalName; }
		const std::string& getDescription() const noexcept { return m_description; }
		const std::vector<std::string>& getNameAliases() const noexcept { return m_nameAliases; }
		bool isRequired() const noexcept { return m_isRequired; }

		void registerNameAlias(const std::string& alias) { m_nameAliases.push_back(alias); }
		void registerArgValueFactory(std::unique_ptr<IArgValueFactory> factory, int priority) { m_argValueFactories.insert({std::move(factory), priority}); }

		bool isValidValue(const std::vector<std::string>& values) const;

		ArgValue parseValue(const std::vector<std::string>& values) const;

	private:
		std::string m_canonicalName;
		std::string m_description;
		std::vector<std::string> m_nameAliases;

		// Using unordered_map to store factories with int value as priority
		std::unordered_map<std::unique_ptr<IArgValueFactory>, int> m_argValueFactories;
		bool m_isRequired;
		std::vector<std::string> m_defaultValues;
	};
}
