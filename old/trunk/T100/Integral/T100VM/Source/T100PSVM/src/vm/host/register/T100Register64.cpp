#include "T100Register64.h"

T100Register64::T100Register64()
{
    //ctor
    m_value     = 0;
}

T100Register64::~T100Register64()
{
    //dtor
}

T100VOID T100Register64::SetValue(T100UINT64 value)
{
    m_value     = value;
}

T100UINT64 T100Register64::GetValue()
{
    return m_value;
}
