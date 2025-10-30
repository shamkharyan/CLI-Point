#include "core/ActionManager.h"

using namespace ppt::core;

void ActionManager::append(std::unique_ptr<act::AAction> action)
{
	m_undo.push_back(std::move(action));
	m_redo.clear();
}

void ActionManager::undo()
{
	if (!m_undo.empty())
	{
		m_undo.back()->undoAction();
		m_redo.push_back(std::move(m_undo.back()));
		m_undo.pop_back();
	}
}

void ActionManager::redo()
{
	if (!m_redo.empty())
	{
		m_redo.back()->doAction();
		m_undo.push_back(std::move(m_redo.back()));
		m_redo.pop_back();
	}
}