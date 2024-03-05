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

std::string T100Unicode::to_string(std::wstring str)
{
    return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.to_bytes(str);
}

std::wstring T100Unicode::to_wstring(std::string str)
{
    return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes(str);
}
