#pragma once

#include "core/actions/IAction.h"

#include <vector>
#include <memory>

namespace ppt::core
{
	class ActionManager
	{
	public:
		void doAction(std::unique_ptr<act::IAction> action);
		void undo();
		void redo();

		void markSaved() { m_isEdited = false; }
		bool isEdited() const { return m_isEdited; }
	private:
		bool m_isEdited = false;
		std::vector<std::unique_ptr<act::IAction>> m_undo;
		std::vector<std::unique_ptr<act::IAction>> m_redo;
	};
}
