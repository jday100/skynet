#include "T100Button.h"

T100Button::T100Button() :
    T100Control()
{
    //ctor
}

T100Button::T100Button(T100Window* parent, T100WSTRING label) :
    T100Control()
{
    //ctor
    T100ButtonStyle     style;

    style.WindowLabel   = label;

    T100Control::Create(parent, &style);
}

T100Button::~T100Button()
{
    //dtor
}

T100VOID T100Button::Create(T100Window* parent, T100WSTRING label, T100ButtonStyle* style)
{
    if(!style){
        T100ButtonStyle         thisStyle;
        thisStyle.WindowLabel   = label;
        style   = &thisStyle;
        T100Control::Create(parent, style);
    }else{
        style->WindowLabel      = label;
        T100Control::Create(parent, style);
    }

}
