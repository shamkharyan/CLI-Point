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

        void addAction(std::unique_ptr<IAction> action)
        {
            m_actions.push_back(std::move(action));
        }

        std::unique_ptr<IAction> doAction() override
        {
            std::vector<std::unique_ptr<IAction>> undoActions;
            undoActions.reserve(m_actions.size());

            for (auto& action : m_actions)
            {
                auto undo = action->doAction();
                undoActions.push_back(std::move(undo));
            }

            auto undoGroup = std::make_unique<GroupAction>();

            for (auto it = undoActions.rbegin(); it != undoActions.rend(); ++it)
                undoGroup->addAction(std::move(*it));

            return undoGroup;
        }

    private:
        std::vector<std::unique_ptr<IAction>> m_actions;
    };

}
