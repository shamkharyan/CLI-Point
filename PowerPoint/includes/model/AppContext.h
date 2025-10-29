#pragma once

#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <memory>

namespace ppt::model
{
	class AppContext
	{
	public:
		AppContext() = default;

		std::shared_ptr<Presentation> getPresentation() { return m_presentation; }
		core::ActionManager& getActionManager() { return m_manager; }
		void setPresentation(std::shared_ptr<Presentation> presentation) { m_presentation = presentation; }

	private:
		std::shared_ptr<Presentation> m_presentation;
		core::ActionManager m_manager;
	};
}
