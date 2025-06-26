#include "gui/layout/T100Layout.h"

namespace T100WINDOWS{

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
    m_parent    = parent;
}

T100VOID T100Layout::SetChildren(T100TREE_VECTOR& children)
{
    m_children  = &children;
}

}
