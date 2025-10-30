#pragma once

#include "core/actions/AAction.h"

#include <vector>
#include <memory>

namespace ppt::core
{
	class ActionManager
	{
	public:
		ActionManager() = default;
		void append(std::unique_ptr<act::AAction> action);
		void undo();
		void redo();
	private:
		std::vector<std::unique_ptr<act::AAction>> m_undo;
		std::vector<std::unique_ptr<act::AAction>> m_redo;
	};
}
