#pragma once

namespace ppt::cli::cmds
{
	class ICommand
	{
	public:
		virtual ~ICommand() = default;
		virtual void execute() = 0;
	};
}
