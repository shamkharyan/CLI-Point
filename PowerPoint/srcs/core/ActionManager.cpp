#include "core/ActionManager.h"

using namespace ppt::core;

void ActionManager::doAction(std::unique_ptr<act::IAction> action)
{
	auto undoAction = action->doAction();
	m_undo.push_back(std::move(undoAction));
	m_redo.clear();
}

void ActionManager::undo()
{
	if (!m_undo.empty())
	{
		auto redoAction = m_undo.back()->doAction();
		m_redo.push_back(std::move(redoAction));
		m_undo.pop_back();
	}
}

void ActionManager::redo()
{
	if (!m_redo.empty())
	{
		auto undoAction = m_redo.back()->doAction();
		m_undo.push_back(std::move(undoAction));
		m_redo.pop_back();
	}
}