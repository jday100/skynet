#include "T100Register32.h"

namespace T100QU32{

T100Register32::T100Register32()
{
    //ctor
    m_value = 0;
}

T100Register32::~T100Register32()
{
    //dtor
}

T100VOID T100Register32::setValue(T100WORD value)
{
    m_value = value;
}

T100WORD T100Register32::getValue()
{
    return m_value;
}

}
