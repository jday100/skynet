#include "T100AUDevice.h"

#include "T100HintQU32.h"
#include "T100QU32.h"


T100AUDevice::T100AUDevice(IComputer* host)
    :m_host(host)
{
    //ctor
    create();
}

T100AUDevice::~T100AUDevice()
{
    //dtor
    destroy();
}

T100VOID T100AUDevice::create()
{
    T100Log::trace(T100DEVICE_HINT_AU_DEVICE_LOAD);

    m_manager = m_host->getManager();
    m_manager->addDevice(m_id, this);
}

T100VOID T100AUDevice::destroy()
{
    m_manager->removeDevice(m_id);

    T100Log::trace(T100DEVICE_HINT_AU_DEVICE_UNLOAD);
}

T100WORD T100AUDevice::in(T100WORD offset)
{
    T100WORD result = 0;

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

T100VOID T100AUDevice::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return;

    switch(offset){
    case 0:
        {
            switch(value)
            {
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_AU;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100AUMODE_GET:
                {
                    m_data[1] = 1;
                    m_data[2] = 0;
                    m_data[3] = 32;
                }
                break;
            };
        }
        break;
    default:
        m_data[offset] = value;
    };
}
