#include "core/actions/EditPresentationAction.h"
#include "core/errors/MissingPresentationException.h"
#include "model/PPModel.h"
#include "model/Presentation.h"

#include <cassert>

using namespace ppt;
using namespace ppt::core::act;

void EditPresentationAction::doAction()
{
	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (!presentation)
		throw err::MissingPresentationException();

	if (m_name)
	{
		m_oldName = presentation->getName();
		presentation->setName(m_name.value());
	}
}

void EditPresentationAction::undoAction()
{
	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();

	if (m_oldName)
		presentation->setName(m_oldName.value());
}