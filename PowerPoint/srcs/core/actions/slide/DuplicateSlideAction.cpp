#include "core/actions/slide/DuplicateSlideAction.h"
#include "core/errors/MissingPresentationException.h"
#include "core/errors/EmptyPresentationException.h"
#include "model/PPModel.h"
#include "model/Slide.h"

#include <cassert>

using namespace ppt::core::act;

DuplicateSlideAction::DuplicateSlideAction(
    std::optional<std::size_t> at,
    std::optional<std::size_t> to,
    bool go) :
    m_at(at),
    m_to(to),
    m_goto(go)
{
}

bool DuplicateSlideAction::doAction()
{
    if (m_completed)
        return false;

    auto& context = model::PPModel::instance().getContext();
    auto presentation = context.getPresentation();

    if (!presentation)
        throw err::MissingPresentationException();

    if (presentation->empty())
        throw err::EmptyPresentationException();

    auto count = presentation->slidesCount();

    if (!m_at)
        m_at = presentation->getSelectedId();

    if (!m_to)
        m_to = m_at.value() + 1;

    if (m_at >= count || m_to > count)
        throw std::out_of_range("Index out of range");

    if (m_goto)
        m_oldPos = presentation->getSelectedId();

    auto slide = presentation->getSlide(m_at.value());

    // Can change selectedId
    presentation->addSlide(slide, m_to.value());

    if (m_goto)
        presentation->setSelectedId(m_to.value());

    m_completed = true;
    return true;
}

bool DuplicateSlideAction::undoAction()
{
    if (!m_completed)
        return false;

    auto& context = model::PPModel::instance().getContext();
    auto presentation = context.getPresentation();

    assert(presentation);
    assert(!presentation->empty());


    auto count = presentation->slidesCount();
    assert(m_to.has_value());
    assert(m_to.value() < count);

    presentation->removeSlide(m_to.value());

    if (m_goto)
    {
        assert(m_oldPos.has_value());
        assert(m_oldPos.value() < count);
        presentation->setSelectedId(m_oldPos.value());
        m_oldPos = std::nullopt;
    }

    m_completed = false;
    return true;
}