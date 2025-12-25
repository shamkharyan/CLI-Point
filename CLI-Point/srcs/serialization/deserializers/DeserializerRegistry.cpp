#include "serialization/deserializers/DeserializerRegistry.h"

using namespace ppt::ser;

DeserializerRegistry::DeserPtr DeserializerRegistry::getDeserializer(const std::string& name) const noexcept
{
	auto it = m_aliasIndexes.find(name);
	if (it != m_aliasIndexes.end())
		return m_deserializers[it->second];

	return nullptr;
}

void DeserializerRegistry::registerDeserializer(const std::string name, DeserPtr serializer)
{
	m_aliasIndexes[name] = m_deserializers.size();
	m_deserializers.push_back(std::move(serializer));
}
