#include "gui/event/T100CommandEvent.h"

T100CommandEvent::T100CommandEvent() :
    T100Event()
{
    //ctor
}

T100CommandEvent::T100CommandEvent(T100MESSAGE_DATA& data) :
    T100Event(data)
{
    //ctor
}


T100CommandEvent::~T100CommandEvent()
{
    //dtor
}
