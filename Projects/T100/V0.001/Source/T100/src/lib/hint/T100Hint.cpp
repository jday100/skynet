#include "T100Hint.h"

#include <iomanip>
#include <sstream>
#include <iostream>


T100BOOL    T100Hint::m_detail      = T100FALSE;


T100Hint::T100Hint()
{
    //ctor
}

T100Hint::~T100Hint()
{
    //dtor
}

T100STDSTRING T100Hint::hex(T100BYTE& byte)
{
    std::stringstream   str;
    std::string         result;

    str << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (int)byte;

    result = str.str();

    return result;
}

T100STDSTRING T100Hint::hex(T100WORD& value)
{
    std::stringstream   str;
    std::string         result;

    str << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << value;

    result = str.str();

    result.insert(2, " ");
    result.insert(5, " ");
    result.insert(8, " ");

    return result;
}

T100STDSTRING T100Hint::dec(T100BYTE& byte)
{
    std::stringstream   str;
    std::string         result;

    str << std::dec << std::setw(3) << std::setfill('0') << (int)byte;

    result = str.str();

    return result;
}

T100STDSTRING T100Hint::dec(T100WORD& value)
{
    std::stringstream   str;
    std::string         result;

    str << std::dec << std::setw(10) << std::setfill('0') << value;

    result = str.str();

    //0,000,000,000
    result.insert(1, ",");
    result.insert(5, ",");
    result.insert(9, ",");

    return result;
}


