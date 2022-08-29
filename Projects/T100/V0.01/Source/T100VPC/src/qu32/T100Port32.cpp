#include "T100Port32.h"

T100Port32::T100Port32(T100QU32* host)
    :m_host(host)
{
    //ctor
    //create();
}

T100Port32::~T100Port32()
{
    //dtor
    destroy();
}

T100VOID T100Port32::create()
{
    m_cu        = T100NEW T100CUDevice(m_host);
    m_au        = T100NEW T100AUDevice(m_host);
    m_memory    = T100NEW T100MemoryDevice(m_host);
    m_port      = T100NEW T100PortDevice(m_host);
}

T100VOID T100Port32::destroy()
{

}

T100BOOL T100Port32::appendDevice(T100BYTE& id, T100Device* dev)
{
    T100BOOL            result;
    T100INT             value;

    value = m_devices.size() - m_device_limit;

    if(1 <= value){
        return T100FALSE;
    }

    result = dev->load(this);
    if(result){
        m_devices.push_back(dev);
        id = m_devices.size() - 1;
    }

    return result;
}

T100BOOL T100Port32::removeDevice(T100BYTE id)
{
    T100BOOL            result;

    if(id < m_devices.size()){
        result = m_devices[id]->unload();
        if(!result){
            return T100FALSE;
        }

        T100Device* dev = (T100Device*)m_devices[id];
        m_devices[id] = T100NULL;
        return T100TRUE;
    }

    return T100FALSE;
}

T100Device* T100Port32::getDevice(T100BYTE id)
{
    T100Device*     result      = T100NULL;

    if(id < m_devices.size()){
        result = m_devices[id];
    }

    return result;
}

T100BOOL T100Port32::in(T100WORD offset, T100WORD& value)
{
    T100BOOL            result          = T100TRUE;

    return result;
}

T100BOOL T100Port32::out(T100WORD offset, T100WORD value)
{
    T100BOOL            result          = T100TRUE;

    return result;
}

T100BOOL T100Port32::allotBlock(T100BlockDevice* dev, T100WORD length, T100WORD_VECTOR& blocks)
{
    T100BOOL            result          = T100TRUE;

    return result;
}

T100DEVICE_BLOCK* T100Port32::getBlock(T100WORD id)
{

}

T100BOOL T100Port32::allotPage(T100PageDevice* dev, T100WORD length, T100WORD_VECTOR& pages)
{
    T100BOOL            result          = T100TRUE;

    return result;
}

T100DEVICE_PAGE* T100Port32::getPage(T100WORD id)
{

}
