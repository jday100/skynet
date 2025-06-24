#include "T100CommandEvent.h"

namespace T100WINDOWS{

T100CommandEvent::T100CommandEvent(const T100WindowMessageData& message) :
    T100Event(message)
{
    //ctor
}

T100CommandEvent::~T100CommandEvent()
{
    //dtor
}

}
