#include "T100String16.h"

#include "T100Unicode.h"

T100String16::T100String16()
{
    //ctor
}

T100String16::~T100String16()
{
    //dtor
}

T100String16& T100String16::operator=(const T100WSTRING& str)
{
    m_value     = T100Unicode::to_string16(const_cast<T100WSTRING&>(str));
    return *this;
}
