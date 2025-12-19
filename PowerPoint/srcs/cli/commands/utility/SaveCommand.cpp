#include "cli/commands/utility/SaveCommand.h"

#include "cli/commands/ExecutionError.h"

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

SaveCommand::SaveCommand(
	const model::Presentation& presentation,
	const ser::SerializerRegistry& registry,
	const std::string& filePath) :
	m_presentation(presentation),
	m_registry(registry),
	m_filePath(filePath)
{
}

void SaveCommand::execute()
{
	auto serializer = m_registry.getSerializer(getExtension(m_filePath));
	if (!serializer)
		throw ExecutionError("Unknown file extention");

	serializer->serialize(m_presentation, m_filePath);
}