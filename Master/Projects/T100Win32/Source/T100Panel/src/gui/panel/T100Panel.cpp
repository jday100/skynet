#include "T100Panel.h"

T100Panel::T100Panel() :
    T100Window()
{
    //ctor
}

T100Panel::T100Panel(T100Win32Application* app, T100Window* parent) :
    T100Window((T100ApplicationEventHandler*)app, parent)
{
    //ctor
}

T100Panel::~T100Panel()
{
    //dtor
}
