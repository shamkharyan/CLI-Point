#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "model/Presentation.h"
#include "serialization/deserializers/DeserializerRegistry.h"

namespace ppt::cli::factories
{
	class OpenCommandFactory : public ICommandFactory
	{
	public:
		OpenCommandFactory(model::Presentation& presentation, const ser::DeserializerRegistry& registry);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		model::Presentation m_presentation;
		const ser::DeserializerRegistry& m_registry;
	};
}
