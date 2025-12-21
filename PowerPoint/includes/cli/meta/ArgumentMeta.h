#pragma once

#include "cli/parsing/parsers/IArgValueParser.h"
#include "cli/parsing/parsers/ArgValue.h"
#include "cli/meta/ValueSpecificationGroup.h"

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
		using value_specs_container = std::vector<ValueSpecificationGroup>;
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

		void addValueSpecGroup(ValueSpecificationGroup spec) { m_valueSpecs.push_back(std::move(spec)); }
		const value_specs_container& getValueSpecGroups() const noexcept { return m_valueSpecs; }

		bool hasValueSpecGroups() const noexcept { return !m_valueSpecs.empty(); }

		iterator begin() noexcept { return m_argValueFactories.begin(); }
		iterator end() noexcept { return m_argValueFactories.end(); }

		const_iterator begin() const noexcept { return m_argValueFactories.begin(); }
		const_iterator end() const noexcept { return m_argValueFactories.end(); }

		const_iterator cbegin() const noexcept { return m_argValueFactories.cbegin(); }
		const_iterator cend() const noexcept { return m_argValueFactories.cend(); }

		const container& getValueFactories() const { return m_argValueFactories; }

		void registerNameAlias(const std::string& alias);
		void registerArgValueFactory(std::shared_ptr<IArgValueParser> factory);

	private:
		std::string m_canonicalName;
		std::string m_description;
		std::vector<std::string> m_nameAliases;

		value_specs_container m_valueSpecs;
		container m_argValueFactories;

		bool m_isRequired;
		std::optional<ArgValue> m_defaultValue;
	};
}

// --argument		Argument description (type)
//					(required) [default: value]
//					
//					SPECIFICATIONS:
//					Specification group1
//						spec-name1	Specification description [default: value]
//						spec-name2	Specification description [default: value]
// 
//					Specification group1
//						spec-name1	Specification description [default: value]
//						spec-name2	Specification description [default: value]

