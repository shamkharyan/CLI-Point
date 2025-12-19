#include "cli/commands/shape/AddShapeCommand.h"
#include "core/ActionManager.h"
#include "core/actions/shape/AddShapeAction.h"
#include "cli/commands/ExecutionError.h"
#include "model/ShapeData.h"
#include "model/Slide.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

AddShapeCommand::AddShapeCommand(
	model::Presentation& model,
	core::ActionManager& actionManager,
	std::size_t at,
	model::utils::ShapeType type,
	const model::utils::GeometryData& geometry,
	const model::utils::StyleData& style,
	std::size_t zIndex) :
	m_model(model),
	m_actionManager(actionManager),
	m_at(at),
	m_type(type),
	m_geometry(geometry),
	m_style(style),
	m_zIndex(zIndex)
{
}

void AddShapeCommand::execute()
{
	if (m_at >= m_model.slidesCount())
		throw ExecutionError("Slide index out of bounds");

	auto pSlide = m_model.getSlide(m_at);
	if (!pSlide)
		throw ExecutionError("Slide not found");

	auto pLayer = pSlide->getLayer(m_zIndex);
	if (!pLayer)
		throw ExecutionError("Layer not found");

	auto pShapeData = std::make_shared<ShapeData>();
	pShapeData->id = pSlide->getNextId();
	pShapeData->type = m_type;
	pShapeData->geometry = m_geometry;
	pShapeData->style = m_style;

	auto action = std::make_unique<act::AddShapeAction>(pLayer, pShapeData, pLayer->shapesCount());
	m_actionManager.doAction(std::move(action));
}
