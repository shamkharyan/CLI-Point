#include "core/actions/presentation/CreatePresentationAction.h"
#include "model/PPModel.h"
#include "model/Presentation.h"

using namespace ppt;
using namespace ppt::core::act;

CreatePresentationAction::CreatePresentationAction(viewer::IViewer& viewer, const std::optional<std::string>& name) :
	m_name(name),
	m_viewer(viewer)
{
}

bool CreatePresentationAction::doAction()
{
	if (m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	auto presentation = context.getPresentation();
	bool shouldRewrite = true;

	if (presentation)
	{
		auto name = presentation->getName();
		auto ans = m_viewer.askConfirmation("Presentation \"" + name + "\" exists. Rewrite?");
		shouldRewrite = ans.value_or(false);
	}

	if (!shouldRewrite)
		return false;

	if (!m_name)
		m_name = "Untitled";

	m_oldPresentation = presentation;
	context.setPresentation(std::make_shared<model::Presentation>(m_name.value()));
	m_completed = true;
	return true;
}

bool CreatePresentationAction::undoAction()
{
	if (!m_completed)
		return false;

	auto& context = model::PPModel::instance().getContext();
	context.setPresentation(m_oldPresentation);
	m_oldPresentation = nullptr;

	m_completed = false;
	return true;
}