#include "CLIApplication.h"

#include "cli/CommandRegistry.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/CLIController.h"

#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/factories/slide/SetSlideColorCommandFactory.h"
#include "cli/factories/presentation/CreatePresentationCommandFactory.h"
#include "cli/factories/presentation/RenamePresentationCommandFactory.h"
#include "cli/meta/ExitCommandMeta.h"
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

#include <iostream>

using namespace ppt;
using namespace ppt::cli::meta;

CLIApplication& CLIApplication::instance()
{
	static CLIApplication app;
	return app;
}

int CLIApplication::execute()
{
	return m_controller.run();
}

CLIApplication::CLIApplication() : 
	m_controller(m_viewer, m_registry), 
	m_viewer(std::cin, std::cout),
	m_presentation("Untitled"), 
	m_actionManager(m_presentation)
{
	registerCommands();
}

void CLIApplication::registerCommands()
{
	m_registry.registerMeta("exit", std::make_shared<ExitCommandMeta>(m_controller, m_viewer));
	m_registry.registerFactory("add-slide", std::make_shared<AddSlideCommandFactory>());
	m_registry.registerFactory("set-slide-color", std::make_shared<SetSlideColorCommandFactory>());
	m_registry.registerFactory("remove-slide", std::make_shared<RemoveSlideCommandFactory>());
	m_registry.registerFactory("undo", std::make_shared<UndoCommandFactory>());
	m_registry.registerFactory("redo", std::make_shared<RedoCommandFactory>());
	m_registry.registerFactory("list", std::make_shared<ListCommandFactory>(m_viewer));
	m_registry.registerFactory("next-slide", std::make_shared<NextSlideCommandFactory>());
	m_registry.registerFactory("prev-slide", std::make_shared<PrevSlideCommandFactory>());
	m_registry.registerFactory("goto-slide", std::make_shared<GotoSlideCommandFactory>());
	m_registry.registerFactory("move-slide", std::make_shared<MoveSlideCommandFactory>());
	m_registry.registerFactory("duplicate-slide", std::make_shared<DuplicateSlideCommandFactory>());
	m_registry.registerFactory("remove-slide", std::make_shared<RemoveSlideCommandFactory>());
	m_registry.registerFactory("add-shape", std::make_shared<AddShapeCommandFactory>());
	m_registry.registerFactory("move-shape", std::make_shared<MoveShapeCommandFactory>());
	m_registry.registerFactory("remove-shape", std::make_shared<RemoveShapeCommandFactory>());
	m_registry.registerFactory("replace-shape", std::make_shared<ReplaceShapeCommandFactory>());
	m_registry.registerFactory("resize-shape", std::make_shared<ResizeShapeCommandFactory>());
}