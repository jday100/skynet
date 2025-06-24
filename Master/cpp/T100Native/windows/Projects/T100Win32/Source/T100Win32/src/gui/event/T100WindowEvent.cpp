#include "T100WindowEvent.h"

namespace T100WINDOWS{

T100WindowEvent::T100WindowEvent(const T100WindowMessageData& message) :
    T100Event(message)
{
    //ctor
}

T100WindowEvent::~T100WindowEvent()
{
    //dtor
}

}
