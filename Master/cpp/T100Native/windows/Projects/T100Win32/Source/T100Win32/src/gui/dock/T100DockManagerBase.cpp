#include "T100DockManagerBase.h"

#include "gui/T100Frame.h"

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
    T100UINT    length      = m_leftWindows.size();

    if(!length){
        return;
    }

    T100Size    size        = m_frame->GetClientSize();
    T100UINT    value       = size.Height / length;

    size.Height     = value;
    T100Point       point;

    for(T100DOCK_DATA* item : m_leftWindows){
        m_leftSize  = item->INFO.GetBestSize().Width;
    }

    for(T100DOCK_DATA* item : m_leftWindows){
        size.Width      = m_leftSize;

        item->WINDOW->SetSize(size);
        item->WINDOW->SetPosition(point);
        point.Y += value;
    }
}

T100VOID T100DockManagerBase::UpdateRight()
{
    T100UINT    length      = m_rightWindows.size();

    if(!length){
        return;
    }

    T100Size    size        = m_frame->GetClientSize();
    T100UINT    value       = size.Height / length;

    size.Height     = value;
    T100Point       point;

    for(T100DOCK_DATA* item : m_rightWindows){
        m_rightSize = item->INFO.GetBestSize().Width;
    }

    for(T100DOCK_DATA* item : m_rightWindows){
        size.Width      = m_rightSize;

        item->WINDOW->SetSize(size);
        item->WINDOW->SetPosition(point);
        point.Y += value;
    }
}

T100VOID T100DockManagerBase::UpdateTop()
{
    T100UINT    length      = m_topWindows.size();

    if(!length){
        return;
    }

    T100Size    size        = m_frame->GetClientSize();
    T100UINT    value       = size.Width / length;

    size.Width      = value;
    T100Point       point;

    for(T100DOCK_DATA* item : m_topWindows){
        m_topSize   = item->INFO.GetBestSize().Height;
    }

    for(T100DOCK_DATA* item : m_topWindows){
        size.Width      = m_topSize;

        item->WINDOW->SetSize(size);
        item->WINDOW->SetPosition(point);
        point.X += value;
    }
}

T100VOID T100DockManagerBase::UpdateBottom()
{
    T100UINT    length      = m_bottomWindows.size();

    if(!length){
        return;
    }

    T100Size    size        = m_frame->GetClientSize();
    T100UINT    value       = size.Width / length;

    size.Width      = value;
    T100Point       point;

    for(T100DOCK_DATA* item : m_bottomWindows){
        m_bottomSize    = item->INFO.GetBestSize().Height;
    }

    for(T100DOCK_DATA* item : m_bottomWindows){
        size.Width      = m_bottomSize;

        item->WINDOW->SetSize(size);
        item->WINDOW->SetPosition(point);
        point.X += value;
    }
}

T100VOID T100DockManagerBase::UpdateCenter()
{
    if(!m_centerWindow){
        return;
    }

    T100Size    size        = m_frame->GetClientSize();
    T100Size    value;
    T100Point   point;

    value.Width     = size.Width - m_leftSize - m_rightSize;
    value.Height    = size.Height - m_topSize - m_bottomSize;

    point.X         = m_leftSize;
    point.Y         = m_topSize;

    m_centerWindow->WINDOW->SetSize(value);
    m_centerWindow->WINDOW->SetPosition(point);
}

T100VOID T100DockManagerBase::Classify(T100DOCK_DATA* data)
{
    if(!data){
        return;
    }

    T100DOCK_POSITION_TYPE      type        = data->INFO.GetPosition();

    switch(type){
    case T100DOCK_LEFT:
        {
            m_leftWindows.push_back(data);
        }
        break;
    case T100DOCK_RIGHT:
        {
            m_rightWindows.push_back(data);
        }
        break;
    case T100DOCK_TOP:
        {
            m_topWindows.push_back(data);
        }
        break;
    case T100DOCK_BOTTOM:
        {
            m_bottomWindows.push_back(data);
        }
        break;
    case T100DOCK_CENTER:
        {
            m_centerWindow  = data;
        }
        break;
    }
}

}
