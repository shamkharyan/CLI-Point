#pragma once

namespace ppt::core::act
{
	class AAction
	{
	public:
		virtual bool doAction() = 0;
		virtual bool undoAction() = 0;
		virtual ~AAction() = default;
	protected:
		bool m_completed = false;
	};
}
