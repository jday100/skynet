#include "T100Layout.h"

T100Layout::T100Layout()
{
    //ctor
}

T100Layout::~T100Layout()
{
    //dtor
}

T100VOID T100Layout::SetParentPtr(T100Window* parent)
{
    m_parentPtr = parent;
}

T100VOID T100Layout::SetChildren(T100WINDOW_VECTOR& children)
{
    m_childrenPtr   = &children;
}
