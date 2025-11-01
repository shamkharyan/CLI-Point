#pragma once

#include "viewer/IViewer.h"
#include "core/actions/AAction.h"
#include "model/Presentation.h"

#include <string>

namespace ppt::core::act
{
	class GotoSlideAction : public AAction
	{
	public:
		GotoSlideAction(std::size_t pos);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::size_t m_pos;
		std::optional<std::size_t> m_oldPos;
	};
}
