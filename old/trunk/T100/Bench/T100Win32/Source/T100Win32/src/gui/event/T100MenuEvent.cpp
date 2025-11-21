#include "gui/event/T100MenuEvent.h"

namespace T100WINDOWS{

T100MenuEvent::T100MenuEvent(const T100WindowMessageData& message) :
    T100Event(message)
{
    //ctor
    m_id    = LOWORD(m_message.WINDOW_WPARAM);
}

T100MenuEvent::~T100MenuEvent()
{
    //dtor
}

T100VOID T100MenuEvent::SetID(T100UINT id)
{
    m_id        = id;
}

T100UINT T100MenuEvent::GetID()
{
    return m_id;
}

}
