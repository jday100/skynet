#include "T100Mouse.h"

#include "T100Manager32.h"
#include "T100QU32.h"
#include "T100Interrupt32.h"


T100Mouse::T100Mouse()
{
    //ctor
}

T100Mouse::~T100Mouse()
{
    //dtor
}

T100VOID T100Mouse::move(T100MOUSE_DATA* data)
{
    m_mouse.push(data);
    //test
    //T100App::getServe()->getComputer()->interrupt(2);
    //getManager32()->getHost32()->getInterrupt32()->interrupt(T100INT_MOUSE);
}

T100WORD T100Mouse::in(T100WORD offset)
{
    T100WORD result = 0;

    if(offset >= 4)return result;

    result = m_data[offset];

    return result;
}

T100VOID T100Mouse::out(T100WORD offset, T100WORD value)
{
    if(offset >= 4)return;

    switch(offset){
    case 0:
        {
            switch(value)
            {
            case T100DEVICEMODE_TYPE:
                {
                    m_data[1] = T100DEVICE_MOUSE;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            case T100MOUSEMODE_GET:
                {
                    m_data[1] = 3;
                    m_data[2] = 0;
                    m_data[3] = 0;
                }
                break;
            };
        }
        break;
    default:
        m_data[offset] = value;
    };
}

T100BOOL T100Mouse::read()
{
    return T100FALSE;
}
