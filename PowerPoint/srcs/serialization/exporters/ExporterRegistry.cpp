#include "serialization/exporters/ExporterRegistry.h"

using namespace ppt::ser;

ExporterRegistry::ExpPtr ExporterRegistry::getExporter(const std::string& name) const noexcept
{
	auto it = m_aliasIndexes.find(name);
	if (it != m_aliasIndexes.end())
		return m_exporters[it->second];

	return nullptr;
}

void ExporterRegistry::registerExporter(const std::string name, ExpPtr serializer)
{
	m_aliasIndexes[name] = m_exporters.size();
	m_exporters.push_back(std::move(serializer));
}
