#include "T100Button.h"

namespace T100WINDOWS{

T100Button::T100Button() :
    T100Control()
{
    //ctor
}

T100Button::T100Button(T100Window* parent, const T100WSTRING& label) :
    T100Control()
{
    //ctor
    init(parent);
}

T100Button::~T100Button()
{
    //dtor
    uninit();
}

T100VOID T100Button::init(T100Window* parent)
{

}

T100VOID T100Button::uninit()
{

}

T100VOID T100Button::Create(T100Window* parent, T100ButtonStyle* style)
{
    init(parent);
}

T100VOID T100Button::Destroy()
{

}

}
