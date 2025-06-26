#include "gui/T100Colour4.h"

#include <windows.h>

namespace T100WINDOWS{

T100Colour4::T100Colour4() :
    T100Class()
{
    //ctor
}

T100Colour4::T100Colour4(T100COLOUR4_TYPE type) :
    T100Class(),
    m_colour4(type)
{
    //ctor
    init();
}

T100Colour4::~T100Colour4()
{
    //dtor
    uninit();
}

T100VOID T100Colour4::init()
{
    m_colour    = ToColour(m_colour4);
}

T100VOID T100Colour4::uninit()
{

}

T100UINT T100Colour4::GetColour()
{
    return m_colour;
}

T100VOID T100Colour4::SetColour4(T100COLOUR4_TYPE type)
{
    m_colour4       = type;
    init();
}

T100COLOUR4_TYPE T100Colour4::GetColour4()
{
    return m_colour4;
}

T100UINT T100Colour4::ToColour(T100COLOUR4_TYPE type)
{
    T100UINT        result          = 0;

    switch(type){
    case T100COLOUR4_BLACK:
        {
            result  = RGB(0, 0, 0);
        }
        break;
    case T100COLOUR4_WHITE:
        {
            result  = RGB(255, 255, 255);
        }
        break;
    case T100COLOUR4_RED:
        {
            result  = RGB(255, 0, 0);
        }
        break;
    case T100COLOUR4_GREEN:
        {
            result  = RGB(0, 255, 0);
        }
        break;
    case T100COLOUR4_BLUE:
        {
            result  = RGB(0, 0, 255);
        }
        break;
    case T100COLOUR4_YELLOW:
        {
            result  = RGB(255, 255, 0);
        }
        break;
    case T100COLOUR4_PURPLE:
        {
            result  = RGB(255, 0, 255);
        }
        break;
    case T100COLOUR4_CYAN:
        {
            result  = RGB(0, 255, 255);
        }
        break;
    }

    return result;
}

}
