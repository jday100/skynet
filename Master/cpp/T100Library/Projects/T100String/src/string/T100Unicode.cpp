#include "string/T100Unicode.h"

#include <locale>
#include <codecvt>

namespace T100LIBRARY{

T100Unicode::T100Unicode()
{
    //ctor
}

T100Unicode::~T100Unicode()
{
    //dtor
}

T100STRING T100Unicode::ToString8(const T100WSTRING& value)
{
    return (T100STRING)std::wstring_convert<std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>>{}.to_bytes((std::wstring)value);
}

T100WSTRING T100Unicode::ToWString(const T100STRING& value)
{
    return (T100WSTRING)std::wstring_convert<std::codecvt_utf8<wchar_t, 0x10ffff, std::little_endian>>{}.from_bytes((std::string)value);
}

}
