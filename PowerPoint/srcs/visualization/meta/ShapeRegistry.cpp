#include "visualization/meta/ShapeRegistry.h"

using namespace ppt::vis;

void ShapeRegistry::registerShapeMeta(ShapeMeta shapeMeta)
{
    const auto& name = shapeMeta.getName();

    if (m_aliasIndexes.find(name) != m_aliasIndexes.end())
        return;

    m_aliasIndexes[name] = m_shapes.size();
    m_shapes.push_back(std::move(shapeMeta));
}

const ShapeMeta* ShapeRegistry::getShapeMeta(const std::string& name) const noexcept
{
    auto it = m_aliasIndexes.find(name);
    if (it == m_aliasIndexes.end())
        return nullptr;

    return &m_shapes[it->second];
}
