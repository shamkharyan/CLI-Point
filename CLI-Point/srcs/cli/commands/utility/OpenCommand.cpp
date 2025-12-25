#include "cli/commands/utility/OpenCommand.h"

#include "cli/commands/ExecutionError.h"
#include <iostream>

using namespace ppt::cli::cmds;

namespace
{
	std::string getExtension(const std::string& filename)
	{
		size_t pos = filename.find_last_of(".");
		if (pos == std::string::npos)
			return "";
		return filename.substr(pos);
	}
}

OpenCommand::OpenCommand(
	model::Presentation& presentation,
	const ser::DeserializerRegistry& registry,
	const std::string& filePath) :
	m_presentation(presentation),
	m_registry(registry),
	m_filePath(filePath)
{
}

void OpenCommand::execute()
{
	auto deserializer = m_registry.getDeserializer(getExtension(m_filePath));
	if (!deserializer)
		throw ExecutionError("Unknown file extention");

	deserializer->deserialize(m_presentation, m_filePath);
}