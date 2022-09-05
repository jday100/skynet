#include "T100VPCCallback.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"

#include "T100HardwareDialog.h"
#include "T100VPCHardwareDialog.h"
#include "T100VPCSetupDialog.h"

#include "T100VPCHardwareDemoDialog.h"
#include "T100VPCSetupDemoDialog.h"
#include "T100VPCHardwareSelectDemoDialog.h"
#include "T100VPCHardwareSelectDialog.h"

#include "T100VPCDebugDemoFrame.h"

#include "T100VPCDebugFrame.h"


T100VPCServe*       T100VPCCallback::m_serve            = T100NULL;
T100VPCView*        T100VPCCallback::m_view             = T100NULL;


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

    return T100TRUE;
}

T100BOOL T100VPCCallback::frame_menu_start(void* d)
{
    m_view->show();
    m_serve->start();
}

T100BOOL T100VPCCallback::frame_menu_stop(void* d)
{
    m_serve->stop();
    m_view->hide();
}

T100BOOL T100VPCCallback::frame_menu_hardware(void* d)
{
    T100VPCHardwareDialog       dialog(m_view->getFrame());

    if(dialog.ShowModal() == wxID_OK){

    }
}

T100BOOL T100VPCCallback::frame_menu_hardware_select(void* d)
{
    T100VPCHardwareSelectDialog         dialog((wxWindow*)d);

    if(dialog.ShowModal() == wxID_OK){

    }
}

T100BOOL T100VPCCallback::frame_menu_setup(void* d)
{
    T100VPCSetupDialog          dialog(m_view->getFrame());

    dialog.ShowModal();
}

T100BOOL T100VPCCallback::frame_menu_debug(void* d)
{
    m_serve->createCallback();
    m_view->ShowDebug();
}

///
T100BOOL T100VPCCallback::debug_button_run_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->run();
    }else{
        T100QU32Setup::DEBUG_MODE   = T100EXECUTOR_MODE_RUN;
    }
}

T100BOOL T100VPCCallback::debug_button_pause_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->pause();
    }else{
        T100QU32Setup::DEBUG_MODE   = T100EXECUTOR_MODE_STEP;
        T100QU32Setup::DEBUG_STATE  = T100EXECUTOR_STATE_PAUSE;
    }
}

T100BOOL T100VPCCallback::debug_button_step_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->step();
    }else{
        T100QU32Setup::DEBUG_MODE   = T100EXECUTOR_MODE_STEP;
    }
}

T100BOOL T100VPCCallback::debug_button_next_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->next();
    }else{
        T100QU32Setup::DEBUG_MODE   = T100EXECUTOR_MODE_NEXT;
    }
}

T100BOOL T100VPCCallback::debug_button_call_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->nextCall();
    }else{
        T100QU32Setup::DEBUG_MODE   = T100EXECUTOR_MODE_NEXT_CALL;
    }
}

T100BOOL T100VPCCallback::debug_button_return_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->nextReturn();
    }else{
        T100QU32Setup::DEBUG_MODE   = T100EXECUTOR_MODE_NEXT_RETURN;
    }
}

T100BOOL T100VPCCallback::debug_notify_start(void* d)
{
    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);

    if(frame){
        frame->load(m_serve->m_host);
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VPCCallback::debug_notify_stop(void* d)
{

}
