#include "core/actions/GroupAction.h"

using namespace ppt::core::act;

void GroupAction::addAction(std::unique_ptr<IAction> action)
{
    m_actions.push_back(std::move(action));
}

std::unique_ptr<IAction> GroupAction::doAction()
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