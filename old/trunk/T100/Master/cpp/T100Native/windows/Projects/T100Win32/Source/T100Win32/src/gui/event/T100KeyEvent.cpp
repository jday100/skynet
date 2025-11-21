#include "gui/event/T100KeyEvent.h"

namespace T100WINDOWS{

T100KeyEvent::T100KeyEvent(const T100WindowMessageData& message) :
    T100Event(message)
{
    //ctor
}

T100KeyEvent::~T100KeyEvent()
{
    //dtor
}

}
