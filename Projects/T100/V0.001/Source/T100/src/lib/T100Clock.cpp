#include "T100Clock.h"

#include <time.h>
#include <sys/time.h>


T100Clock::T100Clock()
{
    //ctor
}

T100Clock::~T100Clock()
{
    //dtor
}

T100WORD T100Clock::second()
{
    time_t  current;

    current = time(T100NULL);

    return current;
}

T100WORD T100Clock::millisecond()
{
    clock_t     current;

    current = clock();

    return current;
}

T100WORD T100Clock::microsecond()
{
    T100WORD    current;

    timeval     value;

    gettimeofday(&value, T100NULL);

    current = value.tv_sec * 1000000 + value.tv_usec;

    return current;
}

T100WORD T100Clock::nanosecond()
{
    timespec    current;

    clock_gettime(CLOCK_REALTIME, &current);

    return current.tv_sec * 1000000000 + current.tv_nsec;
}
