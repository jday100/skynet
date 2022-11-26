#include "T100VPCCallback.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCConfigDialog.h"


namespace T100VPC{

T100VPCServe*           T100VPCCallback::m_serve                        = T100NULL;
T100VPCView*            T100VPCCallback::m_view                         = T100NULL;


T100VPCCallback::T100VPCCallback()
{
    //ctor
}

T100VPCCallback::~T100VPCCallback()
{
    //dtor
}

T100BOOL T100VPCCallback::init(T100VPCServe* serve, T100VPCView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    m_serve->createCallback();

    return T100TRUE;
}

T100BOOL T100VPCCallback::frame_menu_start(void* d)
{
    T100BOOL        result;

    if(m_serve->running()){
        return T100FALSE;
    }

    result = m_view->start();
    if(result){
        result = m_view->show();
        if(result){
            result = m_serve->start();
        }
    }
    if(!result){
        m_view->stop();
    }
    return result;
}

T100BOOL T100VPCCallback::frame_menu_stop(void* d)
{
    T100BOOL        result;

    if(!m_serve->running()){
        return T100FALSE;
    }

    result = m_view->stop();
    if(result){
        result = m_serve->stop();
    }

    if(!result){
        m_view->start();
    }
    return result;
}

T100BOOL T100VPCCallback::frame_menu_quit(void* d)
{
    if(m_serve->running()){
        m_serve->stop();
    }

    m_view->quit();
}

T100BOOL T100VPCCallback::frame_menu_hardware(void* d)
{
    if(m_serve->running()){
        return T100FALSE;
    }

    m_view->getConfig()->Show();
}

T100BOOL T100VPCCallback::frame_menu_hardware_select(void* d)
{

}

T100BOOL T100VPCCallback::frame_menu_setup(void* d)
{

}

T100BOOL T100VPCCallback::frame_menu_debug(void* d)
{

}

T100BOOL T100VPCCallback::frame_menu_about(void* d)
{

}


T100BOOL T100VPCCallback::notify_thread_stop(void* d)
{
    T100BOOL        result;

    if(m_serve->running()){
        return T100FALSE;
    }

    m_serve->getReturn();

    result = m_view->stop();
    if(result){
        result = m_view->quit();
    }

    return result;
}

}
