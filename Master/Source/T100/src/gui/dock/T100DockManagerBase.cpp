#include "gui/dock/T100DockManagerBase.h"

#include "gui/T100Frame.h"

T100DockManagerBase::T100DockManagerBase() :
    T100Class(),
    m_children(),
    m_names(),
    m_windows()
{
    //ctor
}

T100DockManagerBase::T100DockManagerBase(T100Frame* frame) :
    m_framePtr(frame),
    m_children(),
    m_names(),
    m_windows()
{
    //ctor
}

T100DockManagerBase::~T100DockManagerBase()
{
    //dtor
}

T100VOID T100DockManagerBase::SetFramePtr(T100Frame* frame)
{
    m_framePtr  = frame;
}

T100VOID T100DockManagerBase::UpdateLeft()
{
    T100Size        size    = m_framePtr->GetClientSize();
    T100UINT        length  = m_left.size();
    T100UINT        value   = size.m_y / length;

    size.m_y        = value;
    T100Point       point;

    for(T100DOCK_DATA* item : m_left){
        m_leftSize  = 300;
    }

    for(T100DOCK_DATA* item : m_left){
        size.m_x    = item->INFO.GetBestSize().m_x;

        item->WINDOW->SetSize(size);
        item->WINDOW->SetPosition(point);
        point.m_y += value;
    }
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
    if(!m_center){
        return;
    }

    T100Size        size    = m_framePtr->GetClientSize();
    T100Size        value;

    value.m_x   = size.m_x - m_leftSize - m_rightSize;
    value.m_y   = size.m_y - m_topSize - m_bottomSize;

    T100Point       point;

    point.m_x   = m_leftSize;
    point.m_y   = m_topSize;

    m_center->WINDOW->SetSize(value);
    m_center->WINDOW->SetPosition(point);
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
            m_left.push_back(data);
        }
        break;
    case T100DOCK_RIGHT:
        {
            m_right.push_back(data);
        }
        break;
    case T100DOCK_TOP:
        {
            m_top.push_back(data);
        }
        break;
    case T100DOCK_BOTTOM:
        {
            m_bottom.push_back(data);
        }
        break;
    case T100DOCK_CENTER:
        {
            m_center    = data;
        }
        break;
    }
}
