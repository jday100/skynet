#include "T100VPCServe.h"
#include "T100VPCSetup.h"

#include "T100DeviceInfo.h"
#include "T100Disk.h"
#include "T100Display.h"
#include "T100Keyboard.h"
#include "T100Mouse.h"


T100VPCServe::T100VPCServe()
{
    //ctor
    create();
}

T100VPCServe::~T100VPCServe()
{
    //dtor
    destroy();
}

T100VOID T100VPCServe::create()
{

}

T100VOID T100VPCServe::destroy()
{

}

T100BOOL T100VPCServe::start()
{
    if(m_host){
        return T100FALSE;
    }

    m_host = T100NEW T100QU32();

    if(!load()){
        return T100FALSE;
    }

    return m_host->start();
}

T100BOOL T100VPCServe::stop()
{

}

T100BOOL T100VPCServe::load()
{
    T100BOOL            result          = T100TRUE;

    T100DEVICE_INFO_VECTOR&     devices = T100VPCSetup::getDevices();

    for(T100DeviceInfo* info : devices){
        if(info){
            result = createDevice(m_host, info);
            if(!result){
                return T100FALSE;
            }
        }
    }

    return result;
}

T100BOOL T100VPCServe::createDevice(T100QU32* host, T100DeviceInfo* info)
{
    T100BOOL            result          = T100TRUE;

    switch(info->type){
    case T100DEVICE_DISK:
        {
            T100Disk*       disk;

            disk        = T100NEW T100Disk(host);
        }
        break;
    case T100DEVICE_DISPLAY:
        {
            T100Display*    display;

            display     = T100NEW T100Display(host);
        }
        break;
    case T100DEVICE_KEYBOARD:
        {
            T100Keyboard*   keyboard;

            keyboard    = T100NEW T100Keyboard(host);
        }
        break;
    case T100DEVICE_MOUSE:
        {
            T100Mouse*      mouse;

            mouse       = T100NEW T100Mouse(host);
        }
        break;
    default:
        return T100FALSE;
    }

    return result;
}
