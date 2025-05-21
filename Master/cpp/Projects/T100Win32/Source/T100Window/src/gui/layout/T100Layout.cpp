#include "T100Layout.h"

T100Layout::T100Layout() :
    T100Class()
{
    //ctor
}

T100Layout::~T100Layout()
{
    //dtor
}

T100VOID T100Layout::SetParent(T100Window* parent)
{
    m_parentPtr = parent;
}

T100VOID T100Layout::SetChildren(T100OBJECT_TREE_NODE_VECTOR& children)
{
    m_childrenPtr   = &children;
}
