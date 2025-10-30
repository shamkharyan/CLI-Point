#pragma once

#include "viewer/IViewer.h"
#include "core/actions/AAction.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"

#include <string>

namespace ppt::core::act
{
	class CreatePresentationAction : public AAction
	{
	public:
		CreatePresentationAction(viewer::IViewer& viewer, const std::string& name);

		bool doAction() override;
		bool undoAction() override;
	private:
		std::shared_ptr<model::Presentation> m_oldPresentation;
		std::string m_name;
		viewer::IViewer& m_viewer;
		bool m_completed = false;
	};
}
