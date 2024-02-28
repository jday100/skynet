#include "T100VHDBase.h"

T100VHDBase::T100VHDBase()
{
    //ctor
}

T100VHDBase::~T100VHDBase()
{
    //dtor
}

T100VOID T100VHDBase::setCallback(T100VDiskCallback* callback)
{
    m_callback  = callback;
}
