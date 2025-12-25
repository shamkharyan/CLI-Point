#pragma once

#include "core/actions/IAction.h"
#include "model/Presentation.h"

#include <vector>
#include <memory>

namespace ppt::core
{
	class ActionManager
	{
	public:
		ActionManager(model::Presentation& presentation);

		void doAction(std::unique_ptr<act::IAction> action);
		void undo();
		void redo();

		void markSaved();
	private:
		model::Presentation& m_presentation;
		int m_savePoint;
		std::vector<std::unique_ptr<act::IAction>> m_undoStack;
		std::vector<std::unique_ptr<act::IAction>> m_redoStack;
	};
}
