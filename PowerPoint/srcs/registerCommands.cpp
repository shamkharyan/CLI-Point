#include "cli/utils/registerCommands.h"
#include "cli/CommandRegistry.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/CLIController.h"

#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/factories/slide/SetSlideColorCommandFactory.h"
#include "cli/factories/presentation/CreatePresentationCommandFactory.h"
#include "cli/factories/presentation/RenamePresentationCommandFactory.h"
#include "cli/factories/utility/ExitCommandFactory.h"
#include "cli/factories/slide/RemoveSlideCommandFactory.h"
#include "cli/factories/utility/UndoCommandFactory.h"
#include "cli/factories/utility/RedoCommandFactory.h"
#include "cli/factories/utility/ListCommandFactory.h"
#include "cli/factories/slide/NextSlideCommandFactory.h"
#include "cli/factories/slide/PrevSlideCommandFactory.h"
#include "cli/factories/slide/GotoSlideCommandFactory.h"
#include "cli/factories/slide/MoveSlideCommandFactory.h"
#include "cli/factories/slide/DuplicateSlideCommandFactory.h"
#include "cli/factories/shape/AddShapeCommandFactory.h"
#include "cli/factories/shape/MoveShapeCommandFactory.h"
#include "cli/factories/shape/RemoveShapeCommandFactory.h"
#include "cli/factories/shape/ReplaceShapeCommandFactory.h"
#include "cli/factories/shape/ResizeShapeCommandFactory.h"

using namespace ppt;

void cli::registerCommands(ppt::viewer::cli::CLIViewer& viewer, CLIController& controller)
{
	auto& registry = CommandRegistry::instance();

	registry.registerFactory("create-presentation", std::make_shared<factories::CreatePresentationCommandFactory>(viewer));
	registry.registerFactory("rename-presentation", std::make_shared<factories::RenamePresentationCommandFactory>());
	registry.registerFactory("exit", std::make_shared<factories::ExitCommandFactory>(controller, viewer));
	registry.registerFactory("add-slide", std::make_shared<factories::AddSlideCommandFactory>());
	registry.registerFactory("set-slide-color", std::make_shared<factories::SetSlideColorCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
	registry.registerFactory("undo", std::make_shared<factories::UndoCommandFactory>());
	registry.registerFactory("redo", std::make_shared<factories::RedoCommandFactory>());
	registry.registerFactory("list", std::make_shared<factories::ListCommandFactory>(viewer));
	registry.registerFactory("next-slide", std::make_shared<factories::NextSlideCommandFactory>());
	registry.registerFactory("prev-slide", std::make_shared<factories::PrevSlideCommandFactory>());
	registry.registerFactory("goto-slide", std::make_shared<factories::GotoSlideCommandFactory>());
	registry.registerFactory("move-slide", std::make_shared<factories::MoveSlideCommandFactory>());
	registry.registerFactory("duplicate-slide", std::make_shared<factories::DuplicateSlideCommandFactory>());
	registry.registerFactory("remove-slide", std::make_shared<factories::RemoveSlideCommandFactory>());
	registry.registerFactory("add-shape", std::make_shared<factories::AddShapeCommandFactory>());
	registry.registerFactory("move-shape", std::make_shared<factories::MoveShapeCommandFactory>());
	registry.registerFactory("remove-shape", std::make_shared<factories::RemoveShapeCommandFactory>());
	registry.registerFactory("replace-shape", std::make_shared<factories::ReplaceShapeCommandFactory>());
	registry.registerFactory("resize-shape", std::make_shared<factories::ResizeShapeCommandFactory>());
}