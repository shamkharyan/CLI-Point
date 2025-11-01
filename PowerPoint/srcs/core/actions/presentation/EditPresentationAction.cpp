#include "core/actions/presentation/RenamePresentationAction.h"
#include "core/errors/MissingPresentationException.h"
#include "model/PPModel.h"
#include "model/Presentation.h"

#include <cassert>

using namespace ppt;
using namespace ppt::core::act;

RenamePresentationAction::RenamePresentationAction(const std::optional<std::string>& name) :
	m_name(name)
{
}

bool RenamePresentationAction::doAction()
{
	if (m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (!presentation)
		throw err::MissingPresentationException();

	if (m_name)
	{
		m_oldName = presentation->getName();
		presentation->setName(m_name.value());
	}

	m_completed = true;
	return true;
}

bool RenamePresentationAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (m_oldName)
	{
		presentation->setName(m_oldName.value());
		m_oldName = std::nullopt;
	}

	m_completed = false;
	return true;
}