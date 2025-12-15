//#include "core/actions/slide/MoveSlideAction.h"
//#include "core/errors/MissingPresentationException.h"
//#include "core/errors/EmptyPresentationException.h"
//#include "model/PPModel.h"
//#include "model/Slide.h"
//
//#include <cassert>
//
//using namespace ppt::core::act;
//
//MoveSlideAction::MoveSlideAction(std::optional<std::size_t> at, std::size_t to) :
//	m_at(at),
//	m_to(to)
//{
//}
//
//bool MoveSlideAction::doAction()
//{
//  if (m_completed)
//    return false;
//
//  auto& context = model::PPModel::instance().getContext();
//  auto presentation = context.getPresentation();
//
//  if (!presentation)
//    throw err::MissingPresentationException();
//
//  if (presentation->empty())
//      throw err::EmptyPresentationException();
//
//  if (!m_at)
//    m_at = presentation->getSelectedId();
//
//  if (m_at >= presentation->slidesCount() || m_to > presentation->slidesCount())
//    throw std::out_of_range("Index out of range");
//
//  if (m_at == m_to)
//  {
//    m_completed = true;
//    return true;
//  }
//
//  auto slide = presentation->getSlide(m_at.value());
//  presentation->removeSlide(m_at.value());
//
//  auto adjustedTo = m_to;
//  if (m_at.value() < m_to)
//    --adjustedTo;
//
//  presentation->addSlide(slide, adjustedTo);
//
//  m_completed = true;
//  return true;
//}
//
//bool MoveSlideAction::undoAction()
//{
//  if (!m_completed)
//    return false;
//
//  auto& context = model::PPModel::instance().getContext();
//  auto presentation = context.getPresentation();
//
//  assert(presentation);
//  assert(!presentation->empty());
//
//  if (!m_at || m_to >= presentation->slidesCount())
//    throw std::out_of_range("Index out of range");
//
//  auto slide = presentation->getSlide(m_to);
//
//  presentation->removeSlide(m_to);
//
//  int adjustedAt = m_at.value();
//  if (m_at.value() < m_to)
//    --adjustedAt;
//
//  presentation->addSlide(slide, adjustedAt);
//
//  m_completed = false;
//  return true;
//}