#include "gui/base/T100Colour.h"

#include <windows.h>

T100Colour::T100Colour()
{
    //ctor
}

T100Colour::T100Colour(T100COLOUR_TYPE type)
{
    //ctor
    m_colour    = Colour(type);
}

T100Colour::T100Colour(T100BYTE red, T100BYTE green, T100BYTE blue, T100BYTE alpha)
{
    m_colour    = RGB(red, green, blue);
}

T100Colour::~T100Colour()
{
    //dtor
}

T100DWORD T100Colour::GetColour()
{
    return m_colour;
}

T100DWORD T100Colour::Colour(T100COLOUR_TYPE type)
{
    T100DWORD       result          = 0;

    switch(type){
    case T100COLOUR_TYPE_BLACK:
        {
            result  = RGB(0, 0, 0);
        }
        break;
    case T100COLOUR_TYPE_WHITE:
        {
            result  = RGB(255, 255, 255);
        }
        break;
    case T100COLOUR_TYPE_RED:
        {
            result  = RGB(255, 0, 0);
        }
        break;
    case T100COLOUR_TYPE_GREEN:
        {
            result  = RGB(0, 255, 0);
        }
        break;
    case T100COLOUR_TYPE_BLUE:
        {
            result  = RGB(0, 0, 255);
        }
        break;
    case T100COLOUR_TYPE_YELLOW:
        {
            result  = RGB(255, 255, 0);
        }
        break;
    case T100COLOUR_TYPE_PURPLE:
        {
            result  = RGB(255, 0, 255);
        }
        break;
    case T100COLOUR_TYPE_CYAN:
        {
            result  = RGB(0, 255, 255);
        }
        break;
    }

    return result;
}
