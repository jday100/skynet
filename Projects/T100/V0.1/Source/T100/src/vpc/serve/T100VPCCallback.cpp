#include "T100VPCCallback.h"

#include <wx/log.h>

#include "T100ThisAppCommon.h"
#include "T100App.h"
#include "T100Main.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCConfigHardwareDialog.h"
#include "T100VPCConfigHardwareAppendDialog.h"

#include "T100VPCDisplay.h"

#include "T100RegisterEventData.h"
#include "T100VPCDebugFrame.h"

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
    m_serve->init();

    return T100TRUE;
}

T100BOOL T100VPCCallback::frame_menu_start(void* d)
{
    T100BOOL        result;

    if(m_serve->running()){
        return T100FALSE;
    }

    m_view->show();

    result = m_view->start();
    if(!result){
        return T100FALSE;
    }

    result = m_serve->start();

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
    if(!result){
        return T100FALSE;
    }

    result = m_serve->stop();

    if(!result){
        m_view->start();
    }
    return result;
}

T100BOOL T100VPCCallback::frame_menu_quit(void* d)
{
    T100BOOL        result;

    if(m_serve->running()){
        result = m_serve->stop();
        if(result){
            result = m_view->stop();
        }
    }else{
        result = T100TRUE;
    }

    if(result){
        //result = m_view->quit();
    }

    if(result){
        wxThreadEvent   event(wxEVT_THREAD, T100Frame::ID_THREAD_CLOSE);

        event.SetInt(T100APP_VPC);
        wxQueueEvent(wxGetApp().getManager()->getFrame(), event.Clone());
    }

    return result;
}

T100BOOL T100VPCCallback::frame_menu_hardware(void* d)
{
    if(m_serve->running()){
        return T100FALSE;
    }

    m_view->getHardwareDialog()->Show();
}

T100BOOL T100VPCCallback::frame_menu_hardware_setup(void* d)
{

}

T100BOOL T100VPCCallback::frame_menu_hardware_append(void* d)
{
    if(m_serve->running()){
        return T100FALSE;
    }

    m_view->getHardwareDialog()->getAppendDialog()->Show();
}

T100BOOL T100VPCCallback::frame_menu_hardware_remove(void* d)
{
    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_menu_hardware_finish(void* d)
{
    return T100TRUE;
}

T100BOOL T100VPCCallback::frame_menu_setup(void* d)
{
    if(m_serve->running()){
        return T100FALSE;
    }

    //m_view->getSetupDialog()->Show();
}

T100BOOL T100VPCCallback::frame_menu_debug(void* d)
{
    m_view->ShowDebugFrame();
}

T100BOOL T100VPCCallback::frame_menu_about(void* d)
{
    wxLogMessage(
                    "Virtual Computer \n"
                    "\n"
                    "Author: ZhengFeng Qu\n"
                    "\n"
                    "JiangSu China\n"
                    "\n"
                    L"Copyright ©2020-2022"
                 );
}

///
T100BOOL T100VPCCallback::debug_button_run_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->run();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_RUN;
    }
}

T100BOOL T100VPCCallback::debug_button_pause_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->pause();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_STEP;
        T100QU32::T100QU32Setup::DEBUG_STATE  = T100QU32::T100EXECUTOR_STATE_PAUSE;
    }
}

T100BOOL T100VPCCallback::debug_button_step_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->step();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_STEP;
    }
}

T100BOOL T100VPCCallback::debug_button_next_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->next();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_NEXT;
    }
}

T100BOOL T100VPCCallback::debug_button_comment_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->nextComment();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_NEXT_COMMENT;
    }
}

T100BOOL T100VPCCallback::debug_button_call_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->nextCall();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_NEXT_CALL;
    }
}

T100BOOL T100VPCCallback::debug_button_return_click(void* d)
{
    if(m_serve->m_host){
        m_serve->m_host->nextReturn();
    }else{
        T100QU32::T100QU32Setup::DEBUG_MODE   = T100QU32::T100EXECUTOR_MODE_NEXT_RETURN;
    }
}

T100BOOL T100VPCCallback::debug_register_update(void* d)
{
    T100RegisterEventData*      data            = T100NULL;

    data = static_cast<T100RegisterEventData*>(d);

    if(data){
        m_view->getDebugFrame()->OnRegisterUpdate(data->TYPE, data->VALUE);
        T100SAFE_DELETE(data);
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VPCCallback::debug_memory_base_update(void* d)
{
    if(!d)return T100FALSE;
    if(!m_serve->m_host)return T100FALSE;

    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);
    if(!frame)return T100FALSE;

    wxString    temp;
    T100LONG    value;

    temp = frame->MemoryBaseComboBox->GetValue();
    if(!temp.ToLongLong(&value)){
        return T100FALSE;
    }

    T100VPCSetup::MEMORY_WINDOW_BEGIN   = value;
    T100VPCSetup::MEMORY_WINDOW_END     = T100VPCSetup::MEMORY_WINDOW_BEGIN + frame->MemoryListView->GetCountPerPage();

    frame->MemoryScrollBar->SetThumbPosition(value);

    frame->updateMemory(m_serve->m_host->getMemory32());

    return T100TRUE;
}

T100BOOL T100VPCCallback::debug_memory_offset_update(void* d)
{
    if(!d)return T100FALSE;
    if(!m_serve->m_host)return T100FALSE;

    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);
    if(!frame)return T100FALSE;

    wxString    temp;
    T100LONG    base;
    T100LONG    offset;

    temp = frame->MemoryBaseComboBox->GetValue();
    if(!temp.ToLongLong(&base)){
        return T100FALSE;
    }

    temp = frame->MemoryOffsetComboBox->GetValue();
    if(!temp.ToLongLong(&offset)){
        return T100FALSE;
    }

    T100VPCSetup::MEMORY_WINDOW_BEGIN   = base + offset;
    T100VPCSetup::MEMORY_WINDOW_END     = T100VPCSetup::MEMORY_WINDOW_BEGIN + frame->MemoryListView->GetCountPerPage();

    frame->MemoryScrollBar->SetThumbPosition(base + offset);

    frame->updateMemory(m_serve->m_host->getMemory32());

    return T100TRUE;
}

T100BOOL T100VPCCallback::debug_port_base_update(void* d)
{
    if(!d)return T100FALSE;
    if(!m_serve->m_host)return T100FALSE;

    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);
    if(!frame)return T100FALSE;

    wxString    temp;
    T100LONG    value;

    temp = frame->PortBaseComboBox->GetValue();
    if(!temp.ToLongLong(&value)){
        return T100FALSE;
    }

    T100VPCSetup::PORT_WINDOW_BEGIN     = value;
    T100VPCSetup::PORT_WINDOW_END       = T100VPCSetup::PORT_WINDOW_BEGIN + frame->PortListView->GetCountPerPage();

    frame->PortScrollBar->SetThumbPosition(value);

    frame->updatePort(m_serve->m_host->getPort32());

    return T100TRUE;
}

T100BOOL T100VPCCallback::debug_port_offset_update(void* d)
{
    if(!d)return T100FALSE;
    if(!m_serve->m_host)return T100FALSE;

    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);
    if(!frame)return T100FALSE;

    wxString    temp;
    T100LONG    base;
    T100LONG    offset;

    temp = frame->PortBaseComboBox->GetValue();
    if(!temp.ToLongLong(&base)){
        return T100FALSE;
    }

    temp = frame->PortOffsetComboBox->GetValue();
    if(!temp.ToLongLong(&offset)){
        return T100FALSE;
    }

    T100VPCSetup::PORT_WINDOW_BEGIN     = base + offset;
    T100VPCSetup::PORT_WINDOW_END       = T100VPCSetup::PORT_WINDOW_BEGIN + frame->PortListView->GetCountPerPage();

    frame->PortScrollBar->SetThumbPosition(base + offset);

    frame->updatePort(m_serve->m_host->getPort32());

    return T100TRUE;
}

///
T100BOOL T100VPCCallback::debug_port_update(void* d)
{
    if(!d)return T100FALSE;
    if(!m_serve->m_host)return T100FALSE;

    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);
    if(!frame)return T100FALSE;

    frame->updatePort(m_serve->m_host->getPort32());

    return T100TRUE;
}

T100BOOL T100VPCCallback::debug_notify_start(void* d)
{
    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);

    if(frame){
        frame->updateMemory(m_serve->m_host->getMemory32());
        frame->updatePort(m_serve->m_host->getPort32());
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100VPCCallback::debug_notify_stop(void* d)
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

T100BOOL T100VPCCallback::serve_create_display(void* d)
{
    if(!d){
        return T100FALSE;
    }

    T100QU32::T100QU32*     host        = T100NULL;
    T100VPCHost*            frame       = T100NULL;
    T100DisplayInfo*        info        = T100NULL;

    host    = m_serve->m_host;
    info    = static_cast<T100DisplayInfo*>(d);
    frame   = m_view->getHostFrame();

    T100VPCDisplay*    display     = T100NULL;

    display = T100NEW T100VPCDisplay(host, frame, info);
    if(!display){
        return T100FALSE;
    }

    if(!display->create()){
        return T100FALSE;
    }

    return T100TRUE;
}

}
