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
#include "T100VPCHostFrame.h"

#include "T100VPCHostLoadDialog.h"
#include "T100VPCHostRunDialog.h"

#include "T100VPCSetup.h"

#include "T100VPCDisplay.h"


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

T100BOOL T100VPCCallback::serve_create_display(void* d)
{
    if(!d){
        return T100FALSE;
    }

    T100QU32*           host        = T100NULL;
    T100VPCHostFrame*   frame       = T100NULL;

    host    = static_cast<T100QU32*>(d);
    frame   = m_view->getHostFrame();

    T100VPCDisplay*    display     = T100NULL;

    display = T100NEW T100VPCDisplay(host, frame);
    if(!display){
        return T100FALSE;
    }

    if(!display->create()){
        return T100FALSE;
    }

    return T100TRUE;
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
    //m_serve->createCallback();
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

T100BOOL T100VPCCallback::debug_memory_offset_update(void* d)
{
    if(!d)return T100FALSE;
    if(!m_serve->m_host)return T100FALSE;

    T100VPCDebugFrame*      frame   = T100NULL;

    frame = static_cast<T100VPCDebugFrame*>(d);
    if(!frame)return T100FALSE;

    wxString    temp;
    T100LONG    value;

    temp = frame->MemoryOffsetComboBox->GetValue();
    if(!temp.ToLongLong(&value)){
        return T100FALSE;
    }

    T100VPCSetup::MEMORY_WINDOW_BEGIN   = value;
    T100VPCSetup::MEMORY_WINDOW_END     = T100VPCSetup::MEMORY_WINDOW_BEGIN + frame->MemoryListView->GetCountPerPage();

    frame->MemoryScrollBar->SetThumbPosition(value);

    frame->updateMemory(m_serve->m_host->getMemory32());

    return T100TRUE;
}

T100BOOL T100VPCCallback::debug_port_offset_update(void* d)
{

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

T100BOOL T100VPCCallback::host_menu_load(void* d)
{
    T100VPCHostFrame*       frame       = T100NULL;

    frame = static_cast<T100VPCHostFrame*>(d);

    if(frame){
        T100BOOL                    result;
        T100VPCHostLoadDialog       dialog(frame);
        T100LONG                    location;

        if(dialog.ShowModal() == wxID_OK){
            if(dialog.ComboBoxLocation->GetValue().ToLongLong(&location)){
                return m_serve->m_host->load(dialog.ComboBoxFile->GetValue().ToStdWstring(), location);
            }else{
                return T100FALSE;
            }
        }
    }
    return T100FALSE;
}

T100BOOL T100VPCCallback::host_menu_run(void* d)
{
    T100VPCHostFrame*       frame       = T100NULL;

    frame = static_cast<T100VPCHostFrame*>(d);

    if(frame){
        T100BOOL                    result;
        T100VPCHostRunDialog        dialog(frame);
        T100LONG                    base;
        T100LONG                    offset;

        if(dialog.ShowModal() == wxID_OK){
            if(dialog.ComboBoxBase->GetValue().ToLongLong(&base)){

            }else{
                return T100FALSE;
            }
            if(dialog.ComboBoxOffset->GetValue().ToLongLong(&offset)){

            }else{
                return T100FALSE;
            }

            return m_serve->run(base, offset);
        }
    }
    return T100FALSE;
}
