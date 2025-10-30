#pragma once

#include "viewer/IViewer.h"
#include "core/actions/AAction.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"

#include <string>

namespace ppt::core::act
{
	class PrevSlideAction : public AAction
	{
	public:
		PrevSlideAction() = default;

		bool doAction() override;
		bool undoAction() override;
	};
}
