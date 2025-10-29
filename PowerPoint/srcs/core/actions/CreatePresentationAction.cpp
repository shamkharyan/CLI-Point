#include "core/actions/CreatePresentationAction.h"
#include "model/PPModel.h"
#include "model/Presentation.h"

using namespace ppt;
using namespace ppt::core::act;

void CreatePresentationAction::doAction()
{
	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();
	bool shouldRewrite = true;

	if (presentation)
	{
		auto name = presentation->getName();
		auto ans = m_viewer.askConfirmation("Presentation \"" + name + "\" exists. Rewrite?");
		shouldRewrite = ans.value_or(false);
	}
	if (shouldRewrite)
	{
		m_oldPresentation = presentation;
		context.setPresentation(std::make_shared<model::Presentation>(m_name));
		m_completed = true;
	}
}

void CreatePresentationAction::undoAction()
{
	if (m_completed)
	{
		auto& context = model::PPModel::instance().getContext();
		context.setPresentation(m_oldPresentation);
		m_completed = false;
	}
}