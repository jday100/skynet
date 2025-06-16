#include "T100Control.h"

namespace T100WINDOWS{

T100Control::T100Control() :
    T100Window()
{
    //ctor
}

T100Control::T100Control(T100Window* parent) :
    T100Window()
{
    //ctor
    init(parent);
}

T100Control::~T100Control()
{
    //dtor
    uninit();
}

T100VOID T100Control::init(T100Window* parent)
{

}

T100VOID T100Control::uninit()
{

}

T100VOID T100Control::Create(T100Window* parent, T100WindowStyle* style)
{
    init(parent);
}

T100VOID T100Control::Destroy()
{

}

}
