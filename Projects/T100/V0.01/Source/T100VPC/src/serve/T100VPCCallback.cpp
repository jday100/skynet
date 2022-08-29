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
#include "T100VPCDebugDemoDialog.h"


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
    T100VPCSetupDemoDialog          dialog(m_view->getFrame());

    dialog.ShowModal();
}

T100BOOL T100VPCCallback::frame_menu_debug(void* d)
{
    T100VPCDebugDemoDialog          dialog(m_view->getFrame());

    dialog.Show(false);
}
