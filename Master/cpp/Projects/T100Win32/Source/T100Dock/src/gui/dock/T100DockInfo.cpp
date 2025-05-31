#include "gui/T100DockInfo.h"

T100DockInfo::T100DockInfo() :
    T100Class()
{
    //ctor
}

T100DockInfo::~T100DockInfo()
{
    //dtor
}

T100DOCK_POSITION_TYPE& T100DockInfo::GetPosition()
{
    return m_position;
}

T100Size& T100DockInfo::GetMaxSize()
{
    return m_maxSize;
}

T100Size& T100DockInfo::GetMinSize()
{
    return m_minSize;
}

T100Size& T100DockInfo::GetBestSize()
{
    return m_bestSize;
}

T100DockInfo& T100DockInfo::Caption(T100WSTRING value)
{
    m_caption   = value;
    return *this;
}

T100DockInfo& T100DockInfo::CloseButton(T100BOOL flag)
{
    m_closeButton   = flag;
    return *this;
}

T100DockInfo& T100DockInfo::Direction()
{

}

T100DockInfo& T100DockInfo::Left()
{
    m_position  = T100DOCK_LEFT;
    return *this;
}

T100DockInfo& T100DockInfo::Right()
{
    m_position  = T100DOCK_RIGHT;
    return *this;
}

T100DockInfo& T100DockInfo::Top()
{
    m_position  = T100DOCK_TOP;
    return *this;
}

T100DockInfo& T100DockInfo::Bottom()
{
    m_position  = T100DOCK_BOTTOM;
    return *this;
}

T100DockInfo& T100DockInfo::Center()
{
    m_position  = T100DOCK_CENTER;
    return *this;
}

T100DockInfo& T100DockInfo::MaxSize(T100INT x, T100INT y)
{
    m_maxSize   = {x, y};
    return *this;
}

T100DockInfo& T100DockInfo::MaxSize(T100Size& size)
{
    m_maxSize   = size;
    return *this;
}

T100DockInfo& T100DockInfo::MinSize(T100INT x, T100INT y)
{
    m_minSize   = {x, y};
    return *this;
}

T100DockInfo& T100DockInfo::MinSize(T100Size& size)
{
    m_minSize   = size;
    return *this;
}

T100DockInfo& T100DockInfo::BestSize(T100INT x, T100INT y)
{
    m_bestSize  = {x, y};
    return *this;
}

T100DockInfo& T100DockInfo::BestSize(T100Size& size)
{
    m_bestSize  = size;
    return *this;
}
