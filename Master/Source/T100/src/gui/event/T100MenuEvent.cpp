#include "gui/event/T100MenuEvent.h"

T100MenuEvent::T100MenuEvent() :
    T100Event()
{
    //ctor
}

T100MenuEvent::T100MenuEvent(T100MESSAGE_DATA& data) :
    T100Event(data)
{
    //ctor
}

T100MenuEvent::~T100MenuEvent()
{
    //dtor
}
