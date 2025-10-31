#include "cli/utils/registerCommands.h"
#include "cli/CommandRegistry.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/CLIController.h"

#include "cli/factories/AddSlideCommandFactory.h"
#include "cli/factories/EditSlideCommandFactory.h"
#include "cli/factories/CreatePresentationCommandFactory.h"
#include "cli/factories/EditPresentationCommandFactory.h"
#include "cli/factories/ExitCommandFactory.h"
#include "cli/factories/RemoveSlideCommandFactory.h"
#include "cli/factories/UndoCommandFactory.h"
#include "cli/factories/RedoCommandFactory.h"
#include "cli/factories/ListCommandFactory.h"
#include "cli/factories/NextSlideCommandFactory.h"
#include "cli/factories/PrevSlideCommandFactory.h"
#include "cli/factories/GotoSlideCommandFactory.h"
#include "cli/factories/MoveSlideCommandFactory.h"

using namespace ppt;

void cli::registerCommands(ppt::viewer::cli::CLIViewer& viewer, CLIController& controller)
{
	auto& registry = CommandRegistry::instance();

	registry.registerFactory("create-presentation", std::make_shared<factories::CreatePresentationCommandFactory>(viewer));
	registry.registerFactory("edit-presentation", std::make_shared<factories::EditPresentationCommandFactory>());
	registry.registerFactory("exit", std::make_shared<factories::ExitCommandFactory>(controller, viewer));
	registry.registerFactory("add-slide", std::make_shared<factories::AddSlideCommandFactory>());
	registry.registerFactory("edit-slide", std::make_shared<factories::EditSlideCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
	registry.registerFactory("undo", std::make_shared<factories::UndoCommandFactory>());
	registry.registerFactory("redo", std::make_shared<factories::RedoCommandFactory>());
	registry.registerFactory("list", std::make_shared<factories::ListCommandFactory>(viewer));
	registry.registerFactory("next-slide", std::make_shared<factories::NextSlideCommandFactory>());
	registry.registerFactory("prev-slide", std::make_shared<factories::PrevSlideCommandFactory>());
	registry.registerFactory("goto-slide", std::make_shared<factories::GotoSlideCommandFactory>());
	registry.registerFactory("move-slide", std::make_shared<factories::MoveSlideCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
}