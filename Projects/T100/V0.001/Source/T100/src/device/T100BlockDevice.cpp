#include "T100BlockDevice.h"

#include "T100Manager32.h"


T100BlockDevice::T100BlockDevice()
{
    //ctor
}

T100BlockDevice::~T100BlockDevice()
{
    //dtor
}

T100Manager32* T100BlockDevice::getManager32()
{
    return (T100Manager32*)m_manager;
}

T100BOOL T100BlockDevice::load(IManager* m)
{
    return load((T100Manager32*)m);
}

T100BOOL T100BlockDevice::load(T100Manager32* m)
{
    m_manager   = (IManager*)m;
    return T100TRUE;
}

T100BOOL T100BlockDevice::unload()
{
    return T100TRUE;
}

T100WORD T100BlockDevice::in(T100WORD id, T100WORD offset)
{
    T100WORD value;
    T100DEVICE_BLOCK* block     = T100NULL;

    block = getManager32()->getBlock(id);

    if(block){
        value = block->data[offset];
    }else{

    }

    return value;
}

T100VOID T100BlockDevice::out(T100WORD id, T100WORD offset, T100WORD value)
{
    T100DEVICE_BLOCK* block;

    block = getManager32()->getBlock(id);
    if(block){
        block->data[offset] = value;
    }else{

    }
}
