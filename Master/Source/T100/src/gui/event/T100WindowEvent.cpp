#include "gui/event/T100WindowEvent.h"

T100WindowEvent::T100WindowEvent() :
    T100Event()
{
    //ctor
}

T100WindowEvent::T100WindowEvent(T100MESSAGE_DATA& data) :
    T100Event(data)
{
    //ctor
}

T100WindowEvent::~T100WindowEvent()
{
    //dtor
}
