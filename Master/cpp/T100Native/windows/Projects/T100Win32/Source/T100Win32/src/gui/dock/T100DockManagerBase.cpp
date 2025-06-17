#include "T100DockManagerBase.h"

namespace T100WINDOWS{

T100DockManagerBase::T100DockManagerBase() :
    T100Class(),
    m_labels(),
    m_windows(),
    m_children(),
    m_leftWindows(),
    m_rightWindows(),
    m_topWindows(),
    m_bottomWindows()
{
    //ctor
}

T100DockManagerBase::T100DockManagerBase(T100Frame* frame) :
    T100Class(),
    m_frame(frame),
    m_labels(),
    m_windows(),
    m_children(),
    m_leftWindows(),
    m_rightWindows(),
    m_topWindows(),
    m_bottomWindows()
{
    //ctor
}

T100DockManagerBase::~T100DockManagerBase()
{
    //dtor
}

T100VOID T100DockManagerBase::SetFrame(T100Frame* frame)
{
    m_frame     = frame;
}

T100Frame* T100DockManagerBase::GetFrame()
{
    return m_frame;
}

T100VOID T100DockManagerBase::UpdateLeft()
{

}

T100VOID T100DockManagerBase::UpdateRight()
{

}

T100VOID T100DockManagerBase::UpdateTop()
{

}

T100VOID T100DockManagerBase::UpdateBottom()
{

}

T100VOID T100DockManagerBase::UpdateCenter()
{

}

T100VOID T100DockManagerBase::Classify(T100DOCK_DATA*)
{

}

}
