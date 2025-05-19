#include "T100DockManagerBase.h"

#include "T100Frame.h"

T100DockManagerBase::T100DockManagerBase() :
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
    T100UINT        value   = size.height / length;

    size.height     = value;
    T100Point       point;

    for(T100DOCK_DATA* item : m_left){
        m_leftSize  = item->INFO.GetBestSize().width;
    }

    for(T100DOCK_DATA* item : m_left){
        size.width      = m_leftSize;

        item->WINDOW->SetSize(size);
        item->WINDOW->SetPosition(point);
        point.y += value;
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

    value.width     = size.width - m_leftSize - m_rightSize;
    value.height    = size.height - m_topSize - m_bottomSize;

    T100Point       point;

    point.x         = m_leftSize;
    point.y         = m_topSize;

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
