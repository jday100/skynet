#include "T100WxThreadTask.h"

T100WxThreadTask::T100WxThreadTask()
    :T100ThreadTask()
{
    //ctor
}

T100WxThreadTask::~T100WxThreadTask()
{
    //dtor
}

T100VOID T100WxThreadTask::setEvtHandler(wxEvtHandler* handler)
{
    m_handler   = handler;
}

T100VOID T100WxThreadTask::send(wxThreadEvent& event)
{
    wxQueueEvent(m_handler, event.Clone());
}
