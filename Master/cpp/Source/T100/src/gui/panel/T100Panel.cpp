#include "gui/T100Panel.h"

T100Panel::T100Panel() :
    T100Window()
{
    //ctor
}

T100Panel::T100Panel(T100Window* parent) :
    T100Window()
{
    //ctor
    T100PanelStyle      style;
    T100Window::Create(T100NULL, parent, &style);
}

T100Panel::~T100Panel()
{
    //dtor
}

T100VOID T100Panel::Create(T100Window* parent, T100PanelStyle* style)
{
    if(!style){
        T100PanelStyle      thisStyle;
        style       = &thisStyle;
    }
    T100Window::Create(T100NULL, parent, style);
}
