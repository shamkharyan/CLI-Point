#include "core/ActionManager.h"

using namespace ppt::core;

ActionManager::ActionManager(model::Presentation& presentation) : m_presentation(presentation), m_savePoint(0) {}

void ActionManager::doAction(std::unique_ptr<act::IAction> action)
{
	auto undoAction = action->doAction();
	m_undoStack.push_back(std::move(undoAction));

	if (m_savePoint > static_cast<int>(m_undoStack.size()) - 1)
		m_savePoint = -1;

	m_redoStack.clear();
	m_presentation.setModified(m_savePoint != static_cast<int>(m_undoStack.size()));
}

void ActionManager::undo()
{
	if (!m_undoStack.empty())
	{
		auto redoAction = m_undoStack.back()->doAction();
		m_redoStack.push_back(std::move(redoAction));
		m_undoStack.pop_back();

		m_presentation.setModified(m_savePoint != static_cast<int>(m_undoStack.size()));
	}
}

void ActionManager::redo()
{
	if (!m_redoStack.empty())
	{
		auto undoAction = m_redoStack.back()->doAction();
		m_undoStack.push_back(std::move(undoAction));
		m_redoStack.pop_back();

		m_presentation.setModified(m_savePoint != static_cast<int>(m_undoStack.size()));
	}
}

void ActionManager::markSaved()
{
	m_savePoint = static_cast<int>(m_undoStack.size());
	m_presentation.setModified(false);
}