#include "T100Event.h"

namespace T100WINDOWS{

T100Event::T100Event(const T100WindowMessageData& message) :
    T100Class(),
    m_message(message)
{
    //ctor
}

T100Event::~T100Event()
{
    //dtor
}

}
