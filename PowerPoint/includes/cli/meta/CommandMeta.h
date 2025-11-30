#pragma once

#include "cli/factories/ICommandFactory.h"

#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>

namespace ppt::cli::meta
{
	class CommandMeta
	{
	public:
		struct ArgInfo
		{
			std::string desc;
			bool required;
			std::string defaultValue;
		};

	public:
		virtual ~CommandMeta() = default;
		const std::string& getName() const { return m_name; }
		const std::string& getDescription() const { return m_description; }
		std::shared_ptr<factories::ICommandFactory> getFactory() const { return m_factory; }
		bool supportsArgument(const std::string& arg) const { return m_arguments.count(arg) > 0; }
		const std::unordered_map<std::string, ArgInfo>& getArgumentsInfo() const { return m_arguments; }

	protected:
		CommandMeta(
			const std::string& name,
			const std::string& description,
			std::shared_ptr<factories::ICommandFactory> factory,
			const std::unordered_map<std::string, ArgInfo>& arguments) :
			m_name(name),
			m_description(description),
			m_factory(factory),
			m_arguments(arguments)
		{
		}
	protected:
		std::string m_name;
		std::string m_description;
		std::shared_ptr<factories::ICommandFactory> m_factory;
		std::unordered_map<std::string, ArgInfo> m_arguments;
	};
}
