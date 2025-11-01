#include "core/actions/shape/AddShapeAction.h"
#include "core/errors/MissingPresentationException.h"
#include "core/errors/EmptyPresentationException.h"
#include "core/actions/utils/AddShapeParams.h"
#include "model/PPModel.h"
#include "model/Slide.h"
#include "model/Shape.h"

#include <cassert>

using namespace ppt::core;

act::AddShapeAction::AddShapeAction(const utils::AddShapeParams& params) : m_params(params) {}

bool act::AddShapeAction::doAction()
{
	if (m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (!presentation)
		throw err::MissingPresentationException();

	if (presentation->empty())
		throw err::EmptyPresentationException();

	if (!m_params.at)
		m_params.at = presentation->getSelectedId();

	if (m_params.at.value() >= presentation->slidesCount())
		throw std::out_of_range("Index out of range");

	model::Shape shape;
	shape.type = m_params.type.value_or(model::utils::ShapeType::Rectangle);
	shape.geometry.position = m_params.position.value_or(model::utils::Coord(0, 0));
	shape.geometry.size = m_params.size.value_or(model::utils::Coord(100, 100));
	shape.style.backgroundColor = m_params.bgColor.value_or(model::utils::Color(0, 0, 0));
	shape.style.outlineColor = m_params.olColor.value_or(model::utils::Color(255, 0, 0));
	shape.style.outlineThickness = m_params.olThickness.value_or(1);

	if (m_params.text)
		shape.text = model::utils::Text(m_params.text.value());

	m_shapeId = presentation->getNextShapeId(m_params.at.value());
	presentation->addShape(shape, m_params.at.value());

	m_completed = true;
	return true;
}

bool act::AddShapeAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	assert(presentation);
	assert(!presentation->empty());
	assert(m_shapeId.has_value());
	assert(m_params.at.has_value());

	presentation->removeShape(m_shapeId.value(), m_params.at.value());
	m_shapeId = std::nullopt;

	m_completed = false;
	return true;
}
