#include "T100Keyboard.h"

#include "T100QU32.h"


T100Keyboard::T100Keyboard()
{
    //ctor
}

T100Keyboard::~T100Keyboard()
{
    //dtor
}

T100VOID T100Keyboard::key(T100WORD key)
{
    m_keys.push(key);
    //getManager32()->getHost32()->getInterrupt32()->interrupt(T100INT_KEYBOARD);
}

T100WORD T100Keyboard::in(T100WORD offset)
{
    T100WORD result = 0;

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

T100VOID T100Keyboard::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return;

    switch(offset){
    case 0:
        {
            switch(value)
            {
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
            };
        }
        break;
    default:
        m_data[offset] = value;
    };
}

T100BOOL T100Keyboard::read()
{
    return T100FALSE;
}
