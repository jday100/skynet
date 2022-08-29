#include "T100Device.h"

T100Device::T100Device()
{
    //ctor
}

T100Device::~T100Device()
{
    //dtor
}

T100Manager32* T100Device::getManager32()
{
    return (T100Manager32*)m_manager;
}

T100BOOL T100Device::load(IManager* m)
{
    return T100TRUE;
}

T100BOOL T100Device::unload()
{
    return T100TRUE;
}

T100WORD T100Device::in(T100WORD offset)
{
    return 0;
}

T100VOID T100Device::out(T100WORD offset, T100WORD value)
{

}
