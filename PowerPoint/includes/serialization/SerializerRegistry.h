#pragma once

#include "serialization/ISerializer.h"
#include "serialization/IDeserializer.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace ppt::ser
{
	class SerializerRegistry
	{
	public:
		using SerPtr = std::shared_ptr<ISerializer>;
		using DeserPtr = std::shared_ptr<IDeserializer>;

		using container = std::vector<std::pair<SerPtr, DeserPtr>>;
		using alias_container = std::unordered_map<std::string, std::size_t>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		void registerPair(
			const std::string& name,
			SerPtr serializer,
			DeserPtr deserializer);

		SerPtr getSerializer(const std::string& name) const noexcept;
		DeserPtr getDeserializer(const std::string& name) const noexcept;

		iterator begin() noexcept { return m_serializers.begin(); }
		iterator end() noexcept { return m_serializers.end(); }

		const_iterator begin() const noexcept { return m_serializers.begin(); }
		const_iterator end() const noexcept { return m_serializers.end(); }

		const_iterator cbegin() const noexcept { return m_serializers.cbegin(); }
		const_iterator cend() const noexcept { return m_serializers.cend(); }

	private:
		container m_serializers;

		alias_container m_aliasIndexes;
	};
}
