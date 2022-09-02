#include "T100VPCLink.h"

#include <wx/event.h>
#include "T100VPCMain.h"
#include "T100VPCView.h"


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

T100BOOL T100VPCLink::notify_memory_update(T100WORD offset, T100WORD value)
{
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_MEMORY_UPDATE);
    wxQueueEvent(m_view->getFrame(), event.Clone());
}

T100BOOL T100VPCLink::notify_port_update(T100WORD offset, T100WORD value)
{
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PORT_UPDATE);
    wxQueueEvent(m_view->getFrame(), event.Clone());
}
