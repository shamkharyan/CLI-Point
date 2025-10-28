#pragma once

namespace ppt::core::cmds
{
	class ICommand
	{
	public:
		virtual ~ICommand() = default;
		virtual void execute() = 0;
	};
}
