#pragma once

#include "viewer/IViewer.h"
#include "core/actions/AAction.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"

#include <string>

namespace ppt::core::act
{
	class EditPresentationAction : public AAction
	{
	public:
		EditPresentationAction(const std::optional<std::string>& name);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::optional<std::string> m_oldName;
		std::optional<std::string> m_name;
	};
}
