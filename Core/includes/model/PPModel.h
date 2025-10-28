#pragma once

#include "model/AppContext.h"

namespace ppt::model
{
	class PPModel
	{
	public:
		static PPModel& instance();
		AppContext& getContext();
	private:
		PPModel() = default;
		PPModel(const PPModel&) = delete;
		PPModel(PPModel&&) noexcept = delete;
		PPModel& operator=(const PPModel&) = delete;
		PPModel& operator=(PPModel&&) noexcept = delete;
	private:
		AppContext m_context;
	};
}
