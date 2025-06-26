#include "gui/dock/T100DockInfo.h"

namespace T100WINDOWS{

T100DockInfo::T100DockInfo() :
    T100Class()
{
    //ctor
}

T100DockInfo::~T100DockInfo()
{
    //dtor
}

T100DOCK_POSITION_TYPE T100DockInfo::GetPosition()
{
    return m_position;
}

const T100Size& T100DockInfo::GetMaxSize()
{
    return m_maxSize;
}

const T100Size& T100DockInfo::GetMinSize()
{
    return m_minSize;
}

const T100Size& T100DockInfo::GetBestSize()
{
    return m_bestSize;
}

T100DockInfo& T100DockInfo::Caption(const T100WSTRING& label)
{
    m_caption   = label;
    return *this;
}

T100DockInfo& T100DockInfo::CloseButton(T100BOOL flag)
{
    m_closeButton   = flag;
    return *this;
}

T100DockInfo& T100DockInfo::Direction()
{
    return *this;
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

T100DockInfo& T100DockInfo::MaxSize(T100INT width, T100INT height)
{
    m_maxSize   = {width, height};
    return *this;
}

T100DockInfo& T100DockInfo::MaxSize(const T100Size& value)
{
    m_maxSize   = value;
    return *this;
}

T100DockInfo& T100DockInfo::MinSize(T100INT width, T100INT height)
{
    m_minSize   = {width, height};
    return *this;
}

T100DockInfo& T100DockInfo::MinSize(const T100Size& value)
{
    m_minSize   = value;
    return *this;
}

T100DockInfo& T100DockInfo::BestSize(T100INT width, T100INT height)
{
    m_bestSize  = {width, height};
    return *this;
}

T100DockInfo& T100DockInfo::BestSize(const T100Size& value)
{
    m_bestSize  = value;
    return *this;
}

}
