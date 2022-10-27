#include "T100String.h"

#include "T100Unicode.h"

namespace T100Library{

T100String::T100String()
    :m_wstring(), m_string32()
{
    //ctor
}

T100String::T100String(const T100STDCHAR* str)
{
    T100STDSTRING   value;
    T100STRING32    result;

    value           = str;
    m_wstring       = T100Unicode::to_wstring(value);
    result          = T100Unicode::to_string32(m_wstring);
    m_string32      = T100String32(const_cast<T100CHAR32*>(result.data()));
}

T100String::~T100String()
{
    //dtor
}

}
