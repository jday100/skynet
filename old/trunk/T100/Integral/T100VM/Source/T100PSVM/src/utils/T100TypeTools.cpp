#include "T100TypeTools.h"

#include <sstream>
#include <iomanip>

T100TypeTools::T100TypeTools()
{
    //ctor
}

T100TypeTools::~T100TypeTools()
{
    //dtor
}

T100STRING T100TypeTools::to_string(T100UINT64 value)
{
    std::stringstream   ss;

    ss << std::hex << std::uppercase << std::setfill('0') << std::setw(2)  << value;

    return ss.str();
}
