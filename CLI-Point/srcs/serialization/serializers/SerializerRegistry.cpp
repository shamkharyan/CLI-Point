#include "serialization/serializers/SerializerRegistry.h"

using namespace ppt::ser;

SerializerRegistry::SerPtr SerializerRegistry::getSerializer(const std::string& name) const noexcept
{
	auto it = m_aliasIndexes.find(name);
	if (it != m_aliasIndexes.end())
		return m_serializers[it->second];

	return nullptr;
}

void SerializerRegistry::registerSerializer(const std::string name, SerPtr serializer)
{
	m_aliasIndexes[name] = m_serializers.size();
	m_serializers.push_back(std::move(serializer));
}
