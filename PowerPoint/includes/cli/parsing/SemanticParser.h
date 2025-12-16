#pragma once

#include "RawCommand.h"
#include "cli/meta/CommandRegistry.h"
#include "ParsedRawCommand.h"

namespace ppt::cli
{
	class SemanticParser
	{
	public:
		SemanticParser(const CommandRegistry& registry);
		ParsedRawCommand parseRawCommand(const RawCommand& rcmd);
	private:
		const CommandRegistry& commandRegistry;
	};
}
