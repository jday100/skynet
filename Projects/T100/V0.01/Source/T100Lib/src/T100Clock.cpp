#include "T100Clock.h"

#include "time.h"
#include <sys/time.h>
#include <chrono>


T100Clock::T100Clock()
{
    //ctor
}

T100Clock::~T100Clock()
{
    //dtor
}

T100WORD T100Clock::seconds()
{
    time_t  result;

    result = time(T100NULL);

    return static_cast<T100WORD>(result);
}

T100DWORD T100Clock::milliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

T100DWORD T100Clock::microseconds()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

T100DWORD T100Clock::nanoseconds()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
