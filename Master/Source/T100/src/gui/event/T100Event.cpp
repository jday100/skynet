#include "gui/event/T100Event.h"

T100Event::T100Event() :
    T100EventBase()
{
    //ctor
}

T100Event::T100Event(T100MESSAGE_DATA& data) :
    T100EventBase(data)
{
    //ctor
}

T100Event::~T100Event()
{
    //dtor
}
