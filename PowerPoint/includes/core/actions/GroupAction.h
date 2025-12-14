#pragma once

#include "core/actions/IAction.h"

#include <vector>
#include <memory>

namespace ppt::core::act
{
    class GroupAction : public IAction
    {
    public:
        GroupAction() = default;

        void addAction(std::shared_ptr<IAction> action)
        {
            m_actions.push_back(std::move(action));
        }

        std::shared_ptr<IAction> doAction() override
        {
            std::vector<std::shared_ptr<IAction>> undoActions;
            undoActions.reserve(m_actions.size());

            for (auto& action : m_actions)
            {
                auto undo = action->doAction();
                undoActions.push_back(std::move(undo));
            }

            auto undoGroup = std::make_shared<GroupAction>();

            for (auto it = undoActions.rbegin(); it != undoActions.rend(); ++it)
                undoGroup->addAction(*it);

            return undoGroup;
        }

    private:
        std::vector<std::shared_ptr<IAction>> m_actions;
    };

}
