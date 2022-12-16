#include "T100VPCView.h"

#include "T100VPCFrame.h"
#include "T100VPCScreen.h"
#include "T100VPCCallback.h"
#include "T100VPCConfigHardwareDialog.h"

#include "T100VPCHost.h"
#include "T100VPCDebugFrame.h"

namespace T100VPC{

T100VPCView::T100VPCView()
{
    //ctor
    create();
}

T100VPCView::~T100VPCView()
{
    //dtor
    destroy();
}

T100VOID T100VPCView::create()
{
    m_frame = T100NEW T100VPCFrame(T100NULL);
}

T100VOID T100VPCView::destroy()
{
    T100SAFE_DELETE(m_frame);
}

T100VOID T100VPCView::setFrame(T100VPCFrame* frame)
{
    m_frame = frame;
}

T100VPCFrame* T100VPCView::getFrame()
{
    return m_frame;
}

T100VPCHost* T100VPCView::getHostFrame()
{
    return m_host;
}

T100VPCConfigSetupDialog* T100VPCView::getSetupDialog()
{
    if(!m_setup){
        //m_setup = T100NEW T100VPCConfigSetupDialog(m_frame);
    }
    return m_setup;
}

T100VPCConfigHardwareDialog* T100VPCView::getHardwareDialog()
{
    if(!m_hardware){
        m_hardware = T100NEW T100VPCConfigHardwareDialog(m_frame);
    }
    return m_hardware;
}

T100VPCScreen* T100VPCView::getScreen()
{
    //return m_screen;
}

T100BOOL T100VPCView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100VPCView::hide()
{
    if(m_frame){
        return m_frame->Hide();
    }
    return T100FALSE;
}

T100BOOL T100VPCView::run()
{
    return T100VPCCallback::frame_menu_start();
}

T100BOOL T100VPCView::quit()
{
    T100SAFE_DELETE(m_frame);

    if(m_callback){
        (m_parent->*m_callback)(T100NULL);
    }

    return T100TRUE;
}

T100VOID T100VPCView::setCallback(wxFrame* frame, T100WxWidgets::T100FRAME_CALLBACK callback)
{
    m_parent    = frame;
    m_callback  = callback;
}

T100BOOL T100VPCView::start()
{
    T100BOOL        result          = T100FALSE;

    if(m_frame){
        m_frame->StartMenu->Enable(T100FALSE);
        m_frame->StopMenu->Enable(T100TRUE);
        result = T100TRUE;
    }

    if(result){
        if(!m_host){
            m_host = T100NEW T100VPCHost(m_frame);
        }
        m_host->Show();
    }

    if(result){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100VPCView::stop()
{
    if(m_frame){
        m_frame->StartMenu->Enable(T100TRUE);
        m_frame->StopMenu->Enable(T100FALSE);
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100VPCView::ShowDebugFrame()
{
    m_debug = T100NEW T100VPCDebugFrame(m_frame);

    T100VPCSetup::DEBUG         = T100TRUE;
    T100VPCSetup::DEBUG_MODE    = T100QU32::T100EXECUTOR_MODE_RUN;
    T100VPCSetup::DEBUG_STATE   = T100QU32::T100EXECUTOR_STATE_PAUSE;

    m_debug->Show();
}

}
