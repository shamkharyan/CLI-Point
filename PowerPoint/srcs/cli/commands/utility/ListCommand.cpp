//#include "cli/commands/utility/ListCommand.h"
//#include "model/PPModel.h"
//
//using namespace ppt::cli;
//
//cmds::ListCommand::ListCommand(viewer::cli::CLIViewer& viewer) : m_viewer(viewer) {}
//
//void cmds::ListCommand::execute()
//{
//	auto presentation = model::PPModel::instance().getContext().getPresentation();
//	if (!presentation)
//		m_viewer.showText("(no presentation)");
//	else
//		m_viewer.getVisualizer().visualizePresentationSimple(*presentation);
//}
