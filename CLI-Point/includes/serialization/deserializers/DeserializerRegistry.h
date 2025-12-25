#pragma once

#include "IDeserializer.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace ppt::ser
{
	class DeserializerRegistry
	{
	public:
		using DeserPtr = std::shared_ptr<IDeserializer>;

		using container = std::vector<DeserPtr>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

		using alias_container = std::unordered_map<std::string, std::size_t>;
	public:
		void registerDeserializer(const std::string name, DeserPtr serializer);
		DeserPtr getDeserializer(const std::string& name) const noexcept;

		iterator begin() noexcept { return m_deserializers.begin(); }
		iterator end() noexcept { return m_deserializers.end(); }

		const_iterator begin() const noexcept { return m_deserializers.begin(); }
		const_iterator end() const noexcept { return m_deserializers.end(); }

		const_iterator cbegin() const noexcept { return m_deserializers.cbegin(); }
		const_iterator cend() const noexcept { return m_deserializers.cend(); }
	private:
		container m_deserializers;
		alias_container m_aliasIndexes;
	};
}
