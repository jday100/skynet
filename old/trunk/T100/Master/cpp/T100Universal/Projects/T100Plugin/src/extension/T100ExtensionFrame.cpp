#include "T100ExtensionFrame.h"

namespace T100UNIVERSAL{

T100ExtensionFrame::T100ExtensionFrame() :
    T100Extension(),
    m_events()
{
    //ctor
}

T100ExtensionFrame::~T100ExtensionFrame()
{
    //dtor
}

T100Frame* T100ExtensionFrame::GetFrame()
{
    return m_frame;
}

T100VOID T100ExtensionFrame::Bind(T100Frame* frame)
{
    m_frame     = frame;
}

T100VOID T100ExtensionFrame::SignIn(T100INT type, T100EVENT_FUNCTION call, T100EventHandler* handler)
{
    if(!call || !handler){
        return;
    }

    T100EVENT_FUNCTION_DATA         data;

    data.HANDLER    = handler;
    data.FUNCTION   = call;
    m_events[type]  = data;

    m_frame->Connect(type, call, handler);
}

}
