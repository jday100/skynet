#include "T100Time.h"

#include <ctime>
#include <unistd.h>
#include <sys/time.h>

T100Time::T100Time() :
    T100Class()
{
    //ctor
}

T100Time::~T100Time()
{
    //dtor
}

T100WORD T100Time::Now()
{
    time_t      value       = ::time(T100NULL);
    return value;
}

T100WORD T100Time::GetMilliseconds()
{
    struct timeval  value;

    gettimeofday(&value, T100NULL);

    T100WORD        result;

    result  = value.tv_sec * 1000 + value.tv_usec;

    return result;
}

T100WORD T100Time::GetNanoSeconds()
{
    struct timespec     value;

    clock_gettime(CLOCK_REALTIME, &value);

    T100WORD        result;

    result  = value.tv_sec * 1000000 + value.tv_nsec;

    return result;
}
