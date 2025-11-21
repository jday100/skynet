#include "T100Unicode.h"

#include <locale>
#include <codecvt>

T100Unicode::T100Unicode()
{
    //ctor
}

T100Unicode::~T100Unicode()
{
    //dtor
}

T100STRING8 T100Unicode::ToString8(T100WSTRING& str)
{
    return (T100STRING8)std::wstring_convert<std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>>{}.to_bytes((std::wstring)str);
}

T100WSTRING T100Unicode::ToWString(T100STRING8& str)
{
    return (T100WSTRING)std::wstring_convert<std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>>{}.from_bytes((std::string)str);
}
