#include "gui/event/T100PaintEvent.h"

namespace T100WINDOWS{

T100PaintEvent::T100PaintEvent(const T100WindowMessageData& message) :
    T100Event(message)
{
    //ctor
}

T100PaintEvent::~T100PaintEvent()
{
    //dtor
}

}
