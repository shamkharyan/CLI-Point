//#pragma once
//
//#include "core/actions/IAction.h"
//#include "core/actions/slide/RemoveSlideAction.h"
//#include "model/Slide.h"
//#include "model/Presentation.h"
//
//namespace ppt::core::act
//{
//	class AddSlideAction : public IAction
//	{
//	public:
//		AddSlideAction(
//			model::Presentation& presentation, 
//			std::shared_ptr<model::Slide> pSlide,
//			std::size_t index) : 
//			m_presentation(presentation), 
//			m_pSlide(std::move(pSlide)),
//			m_index(index) {}
//
//		std::unique_ptr<IAction> doAction() override
//		{
//			auto it = m_presentation.begin() + m_index;
//			m_presentation.insertSlide(it, m_pSlide);
//
//			return std::make_unique<RemoveSlideAction>(m_presentation, m_index);
//		}
//
//	private:
//		model::Presentation& m_presentation;
//		std::shared_ptr<model::Slide> m_pSlide;
//		std::size_t m_index;
//	};
//}