#pragma once

#include "cli/parsing/IArgValueFactory.h"
#include "cli/parsing/ArgValue.h"

#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace ppt::cli::meta
{
	class ArgumentMeta
	{
	public:
		using container = std::vector<std::unique_ptr<IArgValueFactory>>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		ArgumentMeta(
			const std::string canonicalName,
			const std::string& description,
			bool isRequired,
			std::optional<ArgValue> defaultValue
		);

		const std::string& getCanonicalName() const noexcept { return m_canonicalName; }
		const std::string& getDescription() const noexcept { return m_description; }
		const std::vector<std::string>& getNameAliases() const noexcept { return m_nameAliases; }
		std::optional<ArgValue> getDefaultValue() const noexcept { return m_defaultValue; }
		bool isRequired() const noexcept { return m_isRequired; }

		iterator begin() noexcept { return m_argValueFactories.begin(); }
		iterator end() noexcept { return m_argValueFactories.end(); }

		const_iterator begin() const noexcept { return m_argValueFactories.begin(); }
		const_iterator end() const noexcept { return m_argValueFactories.end(); }

		const_iterator cbegin() const noexcept { return m_argValueFactories.cbegin(); }
		const_iterator cend() const noexcept { return m_argValueFactories.cend(); }

		void registerNameAlias(const std::string& alias);
		void registerArgValueFactory(std::unique_ptr<IArgValueFactory> factory);

		bool isValidValue(const std::vector<std::string>& values) const;
		ArgValue parseValue(const std::vector<std::string>& values) const;

	private:
		std::string m_canonicalName;
		std::string m_description;
		std::vector<std::string> m_nameAliases;
		container m_argValueFactories;
		bool m_isRequired;
		std::optional<ArgValue> m_defaultValue;
	};
}
