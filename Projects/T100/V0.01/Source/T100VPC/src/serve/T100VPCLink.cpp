#include "T100VPCLink.h"

#include <wx/event.h>
#include "T100VPCMain.h"
#include "T100VPCView.h"
#include "T100EventData.h"
#include "T100RegisterEventData.h"


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
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_THREAD_START);
    wxQueueEvent(m_view->getFrame(), event.Clone());

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
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_REGISTER_UPDATE);

    T100RegisterEventData*      data    = T100NEW T100RegisterEventData();

    data->TYPE  = type;
    data->VALUE = value;

    event.SetEventObject(data);

    wxQueueEvent(m_view->getFrame(), event.Clone());
}

T100BOOL T100VPCLink::notify_memory_update(T100WORD offset, T100WORD value)
{
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_MEMORY_UPDATE);

    T100EventData*      data    = T100NEW T100EventData();

    data->OFFSET    = offset;
    data->VALUE     = value;

    event.SetEventObject(data);

    wxQueueEvent(m_view->getFrame(), event.Clone());
}

T100BOOL T100VPCLink::notify_port_update(T100WORD offset, T100WORD value)
{
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PORT_UPDATE);

    T100EventData*      data    = T100NEW T100EventData();

    data->OFFSET    = offset;
    data->VALUE     = value;

    event.SetEventObject(data);

    wxQueueEvent(m_view->getFrame(), event.Clone());
}

T100BOOL T100VPCLink::notify_debug_pause()
{
    wxThreadEvent       event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PAUSE);

    wxQueueEvent(m_view->getFrame(), event.Clone());
}
