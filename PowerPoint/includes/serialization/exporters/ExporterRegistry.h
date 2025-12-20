#pragma once

#include "IExporter.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace ppt::ser
{
	class ExporterRegistry
	{
	public:
		using ExpPtr = std::shared_ptr<IExporter>;

		using container = std::vector<ExpPtr>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

		using alias_container = std::unordered_map<std::string, std::size_t>;
	public:
		void registerExporter(const std::string name, ExpPtr serializer);
		ExpPtr getExporter(const std::string& name) const noexcept;

		iterator begin() noexcept { return m_exporters.begin(); }
		iterator end() noexcept { return m_exporters.end(); }

		const_iterator begin() const noexcept { return m_exporters.begin(); }
		const_iterator end() const noexcept { return m_exporters.end(); }

		const_iterator cbegin() const noexcept { return m_exporters.cbegin(); }
		const_iterator cend() const noexcept { return m_exporters.cend(); }
	private:
		container m_exporters;
		alias_container m_aliasIndexes;
	};
}
