#include "T100Register64.h"

T100Register64::T100Register64()
{
    //ctor
}

T100Register64::~T100Register64()
{
    //dtor
}

T100VOID T100Register64::setValue(T100DWORD value)
{
    m_value = value;
}

T100DWORD T100Register64::getValue()
{
    return m_value;
}
