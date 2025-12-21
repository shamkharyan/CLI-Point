#include "visualization/meta/ShapeMeta.h"

using namespace ppt::vis;

ShapeMeta::ShapeMeta(const std::string& name, const std::shared_ptr<IShapeFactory>& factory)
    : m_name(name), m_factory(factory)
{
}

void ShapeMeta::registerAdjustmentMeta(AdjustmentMeta adjMeta)
{
    auto name = adjMeta.getName();
    if (m_aliasIndexes.find(name) != m_aliasIndexes.end())
        return;

    m_aliasIndexes[name] = m_adjMetas.size();
    m_adjMetas.push_back(std::move(adjMeta));
}

const AdjustmentMeta* ShapeMeta::getAdjustmentMeta(const std::string& adjName) const
{
    auto it = m_aliasIndexes.find(adjName);
    if (it == m_aliasIndexes.end())
        return nullptr;

    return &m_adjMetas[it->second];
}
