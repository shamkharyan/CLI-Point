//#pragma once
//
//#include "cli/factories/ICommandFactory.h"
//#include "cli/commands/ICommand.h"
//#include "core/ActionManager.h"
//#include "model/Presentation.h"
//
//namespace ppt::cli::factories
//{
//	class ClearSlideCommandFactory : public ICommandFactory
//	{
//	public:
//		ClearSlideCommandFactory(
//			core::ActionManager& actionManager,
//			model::Presentation& presentation) : 
//			m_actionManager(actionManager), 
//			m_presentation(presentation) {}
//
//		std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
//
//	private:
//		core::ActionManager& m_actionManager;
//		model::Presentation& m_presentation;
//	};
//}