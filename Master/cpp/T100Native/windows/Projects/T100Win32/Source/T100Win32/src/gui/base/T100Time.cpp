#include "T100Time.h"

#include <ctime>
#include <unistd.h>
#include <sys/time.h>

namespace T100WINDOWS{

T100Time::T100Time() :
    T100Class()
{
    //ctor
}

T100Time::~T100Time()
{
    //dtor
}

T100UINT T100Time::Now()
{
    time_t      value       = ::time(T100NULL);
    return value;
}

T100UINT T100Time::GetMilliSeconds()
{
    T100UINT            result;
    struct timeval      value;

    gettimeofday(&value, T100NULL);

    result  = value.tv_sec * 1000 + value.tv_usec;

    return result;
}

T100UINT T100Time::GetNanoSeconds()
{
    T100UINT            result;
    struct timespec     value;

    clock_gettime(CLOCK_REALTIME, &value);

    result  = value.tv_sec * 1000000 + value.tv_nsec;

    return result;
}

}
