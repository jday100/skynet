#include "gui/event/T100NotifyEvent.h"

namespace T100WINDOWS{

T100NotifyEvent::T100NotifyEvent(const T100WindowMessageData& message) :
    T100Event(message)
{
    //ctor
}

T100NotifyEvent::~T100NotifyEvent()
{
    //dtor
}

T100VOID T100NotifyEvent::SetID(T100UINT id)
{
    m_id        = id;
}

T100UINT T100NotifyEvent::GetID()
{
    return m_id;
}

}
