#include "serialization/SerializerRegistry.h"

using namespace ppt::ser;

void SerializerRegistry::registerPair(
	const std::string& name,
	SerPtr serializer,
	DeserPtr deserializer)
{
	m_aliasIndexes[name] = m_serializers.size();
	m_serializers.emplace_back(std::move(serializer), std::move(deserializer));
}

SerializerRegistry::SerPtr SerializerRegistry::getSerializer(const std::string& name) const noexcept
{
	auto it = m_aliasIndexes.find(name);
	if (it != m_aliasIndexes.end())
		return m_serializers[it->second].first;

	return nullptr;
}

SerializerRegistry::DeserPtr SerializerRegistry::getDeserializer(const std::string& name) const noexcept
{
	auto it = m_aliasIndexes.find(name);
	if (it != m_aliasIndexes.end())
		return m_serializers[it->second].second;

	return nullptr;
}
