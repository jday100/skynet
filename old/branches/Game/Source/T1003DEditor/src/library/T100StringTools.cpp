#include "T100StringTools.h"

#include <locale>

T100StringTools::T100StringTools()
{
    //ctor
}

T100StringTools::~T100StringTools()
{
    //dtor
}

std::string T100StringTools::ToLower(const std::string& str)
{
    std::string lower_case = str;
    std::locale loc;
    for (char& s : lower_case)
        s = std::tolower(s, loc);
    return lower_case;
}

std::wstring T100StringTools::ToLower(const std::wstring& str)
{
    std::wstring lower_case = str;
    std::locale loc;
    for (wchar_t& s : lower_case)
        s = std::tolower(s, loc);
    return lower_case;
}
