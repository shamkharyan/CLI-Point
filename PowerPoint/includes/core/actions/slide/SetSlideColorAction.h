//#pragma once
//
//#include "core/actions/AAction.h"
//#include "model/utils/Color.h"
//
//#include <optional>
//
//namespace ppt::core::act
//{
//	class SetSlideColorAction : public AAction
//	{
//	public:
//		SetSlideColorAction(std::optional<std::size_t> at, model::utils::Color color);
//
//		bool doAction() override;
//		bool undoAction() override;
//	private:
//		std::optional<std::size_t> m_at;
//		model::utils::Color m_color;
//
//		std::optional<model::utils::Color> m_OldColor = std::nullopt;
//	};
//}
