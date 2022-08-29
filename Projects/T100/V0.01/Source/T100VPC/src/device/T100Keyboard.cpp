#include "T100Keyboard.h"

T100Keyboard::T100Keyboard(T100QU32* host)
    :T100Device(host)
{
    //ctor
}

T100Keyboard::~T100Keyboard()
{
    //dtor
}

T100BOOL T100Keyboard::load(T100Port32* port)
{
    return T100TRUE;
}

T100BOOL T100Keyboard::unload()
{
    return T100TRUE;
}

T100BOOL T100Keyboard::in(T100WORD offset, T100WORD& value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    value = m_data[offset];

    return T100TRUE;
}

T100BOOL T100Keyboard::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4){
        return T100FALSE;
    }

    switch(offset){
    case 0:
        {
            switch(value){
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_KEYBOARD;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100KEYBOARDMODE_GET:
                {
                    m_data[1] = 1;
                    m_data[2] = 0;
                    m_data[3] = 32;
                }
                break;
            }
        }
        break;
    default:
        m_data[offset] = value;
    }

    return T100TRUE;
}

