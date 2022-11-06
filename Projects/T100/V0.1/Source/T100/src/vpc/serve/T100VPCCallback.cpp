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
    m_serve     = serve;
    m_view      = view;
}

T100BOOL T100VPCCallback::frame_menu_start(void* d)
{
    if(m_serve->running()){
        return T100FALSE;
    }

    m_view->show();
    m_serve->start();
}

T100BOOL T100VPCCallback::frame_menu_stop(void* d)
{
    if(!m_serve->running()){
        return T100FALSE;
    }

    m_serve->stop();
    m_view->hide();
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

}
