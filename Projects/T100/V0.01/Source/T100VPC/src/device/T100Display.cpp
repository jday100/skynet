#include "T100Display.h"

T100Display::T100Display(T100QU32* host)
    :T100Device(host)
{
    //ctor
}

T100Display::~T100Display()
{
    //dtor
}

T100BOOL T100Display::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100Display::unload()
{
    return T100TRUE;
}

T100BOOL T100Display::in(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100Display::out(T100WORD offset, T100WORD value)
{

}
