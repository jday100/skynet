#include "T100ViewBase.h"

T100ViewBase::T100ViewBase()
{
    //ctor
}

T100ViewBase::~T100ViewBase()
{
    //dtor
}

T100VOID T100ViewBase::SetSize(T100INT width, T100INT height)
{
    m_width     = width;
    m_height    = height;
}
