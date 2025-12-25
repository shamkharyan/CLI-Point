#include "cli/commands/utility/ExportCommand.h"

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

ExportCommand::ExportCommand(
	const model::Presentation& presentation,
	const ser::ExporterRegistry& registry,
	const std::string& filePath,
	std::size_t at) :
	m_presentation(presentation),
	m_registry(registry),
	m_filePath(filePath),
	m_at(at)
{
}

void ExportCommand::execute()
{
	auto exporter = m_registry.getExporter(getExtension(m_filePath));
	if (!exporter)
		throw ExecutionError("Unknown file extention");

	if (m_at >= m_presentation.slidesCount())
		throw ExecutionError("Index out of bounds");

	auto pSlide = m_presentation.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Slide not found");

	exporter->exportSlide(*pSlide, m_filePath);
}