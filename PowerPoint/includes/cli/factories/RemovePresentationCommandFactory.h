#pragma once

#include "cli/factories/ICommandFactory.h"
#include "viewer/IViewer.h"

#include <string>

namespace ppt::cli::factories
{
    class RemovePresentationCommandFactory : public ICommandFactory
    {
    public:
        RemovePresentationCommandFactory(viewer::IViewer& viewer) : m_viewer(viewer) {}
        std::unique_ptr<core::cmds::ICommand> createCommand(const Arguments& args) override;
    private:
        viewer::IViewer& m_viewer;
    };
}
