#include "T100CUDevice.h"

#include "T100HintQU32.h"
#include "T100QU32.h"


T100CUDevice::T100CUDevice(IComputer* host)
    :m_host(host)
{
    //ctor
    create();
}

T100CUDevice::~T100CUDevice()
{
    //dtor
    destroy();
}

T100VOID T100CUDevice::create()
{
    T100Log::trace(T100DEVICE_HINT_CU_DEVICE_LOAD);

    m_manager = m_host->getManager();

    if(!m_manager){
        T100Log::info("Manager ERROR!");
    }

    m_manager->addDevice(m_id, this);
}

T100VOID T100CUDevice::destroy()
{
    m_manager->removeDevice(m_id);

    T100Log::trace(T100DEVICE_HINT_CU_DEVICE_UNLOAD);
}

T100WORD T100CUDevice::in(T100WORD offset)
{
    T100WORD result = 0;

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

T100VOID T100CUDevice::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return;

    switch(offset){
    case 0:
        {
            m_data[0] = value;

            switch(value)
            {
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_CU;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100CUMODE_GET:
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
