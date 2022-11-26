#include "T100VPCLink.h"

#include <wx/event.h>
#include "T100VPCServe.h"
#include "T100VPCView.h"
#include "T100VPCFrame.h"
#include "T100EventData.h"
#include "T100RegisterEventData.h"


namespace T100VPC{

T100VPCServe*       T100VPCLink::m_serve            = T100NULL;
T100VPCView*        T100VPCLink::m_view             = T100NULL;


T100VPCLink::T100VPCLink()
{
    //ctor
}

T100VPCLink::~T100VPCLink()
{
    //dtor
}

T100BOOL T100VPCLink::init(T100VPCServe* serve, T100VPCView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}

T100BOOL T100VPCLink::notify_start()
{
    return T100TRUE;
}

T100BOOL T100VPCLink::notify_stop()
{
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_THREAD_STOP);
    wxQueueEvent(m_view->getFrame(), event.Clone());

    return T100TRUE;
}

T100BOOL T100VPCLink::notify_register_update(T100WORD type, T100WORD value)
{
    return T100TRUE;
}

T100BOOL T100VPCLink::notify_memory_update(T100WORD offset, T100WORD value)
{
    return T100TRUE;
}

T100BOOL T100VPCLink::notify_port_update(T100WORD offset, T100WORD value)
{
    return T100TRUE;
}

T100BOOL T100VPCLink::notify_debug_pause()
{
    return T100TRUE;
}


}
