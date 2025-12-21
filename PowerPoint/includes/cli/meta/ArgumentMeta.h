#pragma once

#include "cli/parsing/parsers/IArgValueParser.h"
#include "cli/parsing/parsers/ArgValue.h"

#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace ppt::cli::meta
{
	class ArgumentMeta
	{
	public:
		using container = std::vector<std::shared_ptr<IArgValueParser>>;
		using notes_container = std::vector<std::string>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		ArgumentMeta(
			const std::string canonicalName,
			const std::string& description,
			bool isRequired
		);

		ArgumentMeta(
			const std::string canonicalName,
			const std::string& description,
			ArgValue defaultValue
		);

		const std::string& getCanonicalName() const noexcept { return m_canonicalName; }
		const std::string& getDescription() const noexcept { return m_description; }
		const std::vector<std::string>& getNameAliases() const noexcept { return m_nameAliases; }
		std::optional<ArgValue> getDefaultValue() const noexcept { return m_defaultValue; }
		bool isRequired() const noexcept { return m_isRequired; }

		void addNote(const std::string& note) { m_notes.push_back(note); }
		const std::vector<std::string>& getNotes() const { return m_notes; }

		iterator begin() noexcept { return m_argValueFactories.begin(); }
		iterator end() noexcept { return m_argValueFactories.end(); }

		const_iterator begin() const noexcept { return m_argValueFactories.begin(); }
		const_iterator end() const noexcept { return m_argValueFactories.end(); }

		const_iterator cbegin() const noexcept { return m_argValueFactories.cbegin(); }
		const_iterator cend() const noexcept { return m_argValueFactories.cend(); }

		void registerNameAlias(const std::string& alias);
		void registerArgValueFactory(std::shared_ptr<IArgValueParser> factory);

	private:
		std::string m_canonicalName;
		std::string m_description;
		std::vector<std::string> m_nameAliases;

		notes_container m_notes;
		container m_argValueFactories;
		bool m_isRequired;
		std::optional<ArgValue> m_defaultValue;
	};
}
