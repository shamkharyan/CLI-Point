#pragma once

#include "RawCommand.h"
#include "cli/CommandRegistry.h"
#include "ValidatedRawCommand.h"

namespace ppt::cli
{
	class SemanticAnalyzer
	{
	public:
		SemanticAnalyzer(const CommandRegistry& registry);
		ValidatedRawCommand analyze(const RawCommand& rcmd);
	private:
		const CommandRegistry& commandRegistry;
	};
}
