#include "T100NotifyEvent.h"

T100NotifyEvent::T100NotifyEvent(T100WindowMessageData& data) :
    T100Event(data)
{
    //ctor
}

T100NotifyEvent::~T100NotifyEvent()
{
    //dtor
}

T100VOID T100NotifyEvent::SetID(T100WORD id)
{
    m_id        = id;
}

T100WORD& T100NotifyEvent::GetID()
{
    return m_id;
}
