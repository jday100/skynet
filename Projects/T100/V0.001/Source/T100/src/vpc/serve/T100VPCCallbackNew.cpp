#include "T100VPCCallbackNew.h"

#include "T100VPCSetup.h"
#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCSetupDialog.h"


T100VPCServe*       T100VPCCallback::m_serve    =   T100NULL;
T100VPCView*        T100VPCCallback::m_view     =   T100NULL;


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
    T100BOOL    result      = T100TRUE;

    if(m_serve->running()){
        return T100FALSE;
    }

    if(result){
        result = m_view->start();
    }

    if(result){
        result = m_serve->create(m_view, T100NULL);
    }

    if(result){
        if(!(m_serve->start())){
            result = T100FALSE;
        }
    }

    if(!result){
        m_view->stop();
    }

    return result;
}

T100BOOL T100VPCCallback::frame_menu_stop(void* d)
{
    T100BOOL    result      = T100TRUE;

    if(m_serve->running()){
        result = m_serve->stop();
    }else{
        return T100FALSE;
    }

    if(result){
        result = m_view->stop();
    }

    return result;
}

T100BOOL T100VPCCallback::frame_menu_quit(void* d)
{
    T100BOOL    result      = T100TRUE;

    m_view->getFrame()->Close();

    return result;
}

T100BOOL T100VPCCallback::frame_menu_setup(void* d)
{
    T100VPCFrame*   frame       = T100NULL;

    if(!m_view){
        return T100FALSE;
    }

    frame   = m_view->getFrame();

    if(!frame){
        return T100FALSE;
    }

    T100VPCSetupDialog  dialog(frame, wxID_ANY, wxDefaultPosition, wxSize(400, 500));

    dialog.ShowModal();

    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_menu_debug(void* d)
{
    if(!m_view){
        return T100FALSE;
    }

    m_view->getDebugFrame()->Show();

    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_event_close(void* d)
{
    return app_quit();
}

T100BOOL T100VPCCallback::frame_debug_log_on(void* d)
{
    T100QU32Setup::DEBUG    = T100TRUE;
    T100Log::start();
    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_debug_log_off(void* d)
{
    T100QU32Setup::DEBUG    = T100FALSE;
    T100Log::stop();
    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_debug_pause(void* d)
{
    if(m_serve){
        m_serve->pause();
    }
    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_debug_run(void* d)
{
    if(m_serve){
        m_serve->resume();
    }
    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_debug_step(void* d)
{
    if(m_serve){
        m_serve->step();
    }
    return T100FALSE;
}

T100BOOL T100VPCCallback::frame_debug_next(void* d)
{
    if(m_serve){
        m_serve->next();
    }
    return T100FALSE;
}

T100BOOL T100VPCCallback::app_quit(void* d)
{
    T100BOOL    result      = T100TRUE;

    if(m_serve->running()){
        result = m_serve->stop();
    }

    if(result){
        result = m_view->quit();
    }

    return result;
}

//

T100BOOL T100VPCCallback::callback_start(void* s, void* v, void* w, void* d)
{
    T100VPCFrame*   frame = (T100VPCFrame*)w;

    if(!frame)return T100FALSE;

    return T100FALSE;
}

T100BOOL T100VPCCallback::callback_stop(void* s, void* v, void* w, void* d)
{
    return T100FALSE;
}

T100BOOL T100VPCCallback::callback_done(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event_done(wxEVT_THREAD, T100VPCFrame::ID_THREAD_DONE);
    wxQueueEvent(frame, event_done.Clone());

    if(T100VPCSetup::m_quit){
        wxThreadEvent event_quit(wxEVT_THREAD, T100VPCFrame::ID_THREAD_QUIT);
        wxQueueEvent(frame, event_quit.Clone());
    }

    return true;
}



T100BOOL T100VPCCallback::callback_debug(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_THREAD_DEBUG);
    wxQueueEvent(frame, event.Clone());

    return true;
}


T100BOOL T100VPCCallback::callback_debug_update(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_THREAD_DEBUG_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}


T100BOOL T100VPCCallback::callback_debug_rom_base_update(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_ROM_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}


T100BOOL T100VPCCallback::callback_debug_ram_base_update(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_RAM_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}



T100BOOL T100VPCCallback::callback_debug_device_update(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_DEVICE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}


T100BOOL T100VPCCallback::callback_debug_block_update(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_BLOCK_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}


T100BOOL T100VPCCallback::callback_debug_page_update(void* s, void* v, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PAGE_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}

