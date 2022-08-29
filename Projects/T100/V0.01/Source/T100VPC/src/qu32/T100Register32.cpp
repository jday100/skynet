#include "T100Register32.h"

T100Register32::T100Register32()
{
    //ctor
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
