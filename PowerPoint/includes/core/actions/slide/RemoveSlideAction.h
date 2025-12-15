//#pragma once
//
//#include "core/actions/IAction.h"
//#include "model/Slide.h"
//
//#include <optional>
//
//namespace ppt::core::act
//{
//	class RemoveSlideAction : public IAction
//	{
//	public:
//		RemoveSlideAction(
//			model::Presentation& presentation,
//			std::size_t index) :
//			m_presentation(presentation),
//			m_index(index)
//		{
//		}
//
//		std::unique_ptr<IAction> doAction() override
//		{
//			auto it = m_presentation.begin() + m_index;
//			auto pSlide = m_presentation.removeSlide(it);
//			return std::make_unique<AddSlideAction>(m_presentation, pSlide, m_index);
//		}
//
//	private:
//		model::Presentation& m_presentation;
//		std::size_t m_index;
//	};
//}
