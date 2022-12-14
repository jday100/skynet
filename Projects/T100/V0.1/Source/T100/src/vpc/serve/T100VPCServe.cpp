#include "T100VPCServe.h"

#include "T100VPCLink.h"
#include "T100VPCAllDevices.h"
#include "T100VPCSetup.h"
#include "T100VPCCallback.h"

#include "T100Disk.h"
#include "T100Keyboard.h"
#include "T100Mouse.h"

namespace T100VPC{

T100VPCServe::T100VPCServe()
{
    //ctor
}

T100VPCServe::~T100VPCServe()
{
    //dtor
}

T100BOOL T100VPCServe::start()
{
    if(m_host){
        return T100FALSE;
    }

    m_host = T100NEW T100QU32::T100QU32();

    if(!createCallback()){
        return T100FALSE;
    }

    if(!init()){
        return T100FALSE;
    }

    if(!m_host->create()){
        return T100FALSE;
    }

    if(!load()){
        return T100FALSE;
    }

    return m_host->start();
}

T100BOOL T100VPCServe::stop()
{
    if(m_host){
        return m_host->halt();
    }
    return T100FALSE;
}

T100BOOL T100VPCServe::running()
{
    if(m_host){
        return m_host->running();
    }
    return T100FALSE;
}

T100BOOL T100VPCServe::createCallback()
{
    if(!m_callback){
        m_callback = T100NEW T100VPCLink();
    }

    if(m_host){
        m_host->setCallback(m_callback);
        return T100TRUE;
    }
    return T100FALSE;
}

T100WORD T100VPCServe::getReturn()
{
    if(m_host){
        m_return = m_host->getReturn();
    }
    return m_return;
}

T100BOOL T100VPCServe::load()
{
    T100BOOL        result          = T100FALSE;

    T100DEVICE_INFO_VECTOR&     devices = T100VPCSetup::getDevices();

    for(T100DeviceInfo* item : devices){
        if(item){
            result = createDevice(m_host, item);
            if(!result){
                return T100FALSE;
            }
        }
    }

    return result;
}

T100BOOL T100VPCServe::init()
{
    T100BOOL                result          = T100FALSE;

    if(!T100VPCSetup::getDevices().empty()){
        return T100TRUE;
    }

    T100CUDeviceInfo*       m_cu            = T100NULL;
    T100AUDeviceInfo*       m_au            = T100NULL;
    T100MemoryInfo*         m_memory        = T100NULL;
    T100PortDeviceInfo*     m_port          = T100NULL;

    T100DisplayInfo*        m_display       = T100NULL;
    T100DiskInfo*           m_disk          = T100NULL;
    T100KeyboardInfo*       m_keyboard      = T100NULL;
    T100MouseInfo*          m_mouse         = T100NULL;

    m_cu        = T100NEW T100CUDeviceInfo();
    m_au        = T100NEW T100AUDeviceInfo();
    m_memory    = T100NEW T100MemoryInfo();
    m_port      = T100NEW T100PortDeviceInfo();

    m_display   = T100NEW T100DisplayInfo();
    m_disk      = T100NEW T100DiskInfo();
    m_keyboard  = T100NEW T100KeyboardInfo();
    m_mouse     = T100NEW T100MouseInfo();

    result = T100VPCSetup::appendDevice(m_cu);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_au);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_memory);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_port);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_display);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_disk);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_keyboard);
    if(!result){
        return T100FALSE;
    }

    result = T100VPCSetup::appendDevice(m_mouse);
    if(!result){
        return T100FALSE;
    }

    return T100TRUE;
}

T100BOOL T100VPCServe::createDevice(T100QU32::T100QU32* host, T100DeviceInfo* info)
{
    T100BOOL            result          = T100TRUE;

    T100WORD            type;

    //test
    type = info->type;

    switch(info->type){
    case T100Component::T100DEVICE_DISK:
        {
            T100Disk*       disk;

            disk        = T100NEW T100Disk(host);
        }
        break;
    case T100Component::T100DEVICE_DISPLAY:
        {
            //T100Display*    display;

            //display     = T100NEW T100VPCDisplay(host);

            T100VPCCallback::serve_create_display(host);
        }
        break;
    case T100Component::T100DEVICE_KEYBOARD:
        {
            T100Keyboard*   keyboard;

            keyboard    = T100NEW T100Keyboard(host);
        }
        break;
    case T100Component::T100DEVICE_MOUSE:
        {
            T100Mouse*      mouse;

            mouse       = T100NEW T100Mouse(host);
        }
        break;
    default:
        return T100TRUE;
    }

    return result;
}

}
