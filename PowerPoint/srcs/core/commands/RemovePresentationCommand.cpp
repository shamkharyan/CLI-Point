#include "core/commands/RemovePresentationCommand.h"
#include "model/PPModel.h"
#include "model/errors/MissingPresentationException.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

RemovePresentationCommand::RemovePresentationCommand(viewer::IViewer& viewer, bool force) :
	m_viewer(viewer),
	m_force(force)
{
}

void RemovePresentationCommand::execute()
{
	auto& context = PPModel::instance().getContext();
	if (!context.presentation)
		throw err::MissingPresentationException();

	bool shouldDelete = true;

	if (!m_force)
	{
		auto name = context.presentation->getName();
		auto ans = m_viewer.askConfirmation("Delete presentation \"" + name + "\"?");
		shouldDelete = ans && ans.value();
	}
	
	if (shouldDelete)
		context.presentation = nullptr;
}