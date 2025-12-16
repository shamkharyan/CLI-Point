#pragma once

#include "core/actions/IAction.h"

#include <vector>
#include <memory>

namespace ppt::core::act
{
    class GroupAction : public IAction
    {
    public:

        void addAction(std::unique_ptr<IAction> action);
        std::unique_ptr<IAction> doAction() override;

    private:
        std::vector<std::unique_ptr<IAction>> m_actions;
    };

}
