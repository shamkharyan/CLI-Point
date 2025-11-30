#pragma once

namespace ppt::core
{
	class IController
	{
	public:
		virtual int run() = 0;
		virtual void exit() = 0;
	};
}
