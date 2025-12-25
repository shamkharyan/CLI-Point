#pragma once

#include <memory>

namespace ppt::core::act
{
	class IAction
	{
	public:
		virtual ~IAction() = default;
		virtual std::unique_ptr<IAction> doAction() = 0;
	};
}