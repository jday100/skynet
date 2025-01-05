#include "T100Timer.h"

T100Timer::T100Timer() :
    m_elapsedTicks(0),
    m_totalTicks(0),
    m_leftOverTicks(0),
    m_frameCount(0),
    m_framesPerSecond(0),
    m_framesThisSecond(0),
    m_qpcSecondCounter(0),
    m_isFixedTimeStep(false),
    m_targetElapsedTicks(TicksPerSecond / 60)
{
    //ctor
    if(!QueryPerformanceFrequency(&m_qpcFrequency))
    {
        throw new std::runtime_error("");
    }

    if(!QueryPerformanceCounter(&m_qpcLastTime))
    {
        throw new std::runtime_error("");
    }

    m_qpcMaxDelta   = m_qpcFrequency.QuadPart / 10;
}

T100Timer::~T100Timer()
{
    //dtor
}

UINT64 T100Timer::GetElapsedTicks() const
{
    return m_elapsedTicks;
}

DOUBLE T100Timer::GetElapsedSeconds() const
{
    return TicksToSeconds(m_elapsedTicks);
}

UINT64 T100Timer::GetTotalTicks() const
{
    return m_totalTicks;
}

DOUBLE T100Timer::GetTotalSeconds() const
{
    return TicksToSeconds(m_totalTicks);
}

UINT32 T100Timer::GetFrameCount() const
{
    return m_frameCount;
}

UINT32 T100Timer::GetFramesPerSecond() const
{
    return m_framesPerSecond;
}

T100VOID T100Timer::SetFixedTimeStep(T100BOOL isFixedTimeStep)
{
    m_isFixedTimeStep = isFixedTimeStep;
}

T100VOID T100Timer::SetTargetElapsedTicks(UINT64 targetElapsed)
{
    m_targetElapsedTicks = targetElapsed;
}

T100VOID T100Timer::SetTargetElapsedSeconds(DOUBLE targetElapsed)
{
    m_targetElapsedTicks = SecondsToTicks(targetElapsed);
}

DOUBLE T100Timer::TicksToSeconds(UINT64 ticks)
{
    return static_cast<double>(ticks) / TicksPerSecond;
}

UINT64 T100Timer::SecondsToTicks(DOUBLE seconds)
{
    return static_cast<UINT64>(seconds * TicksPerSecond);
}

T100VOID T100Timer::ResetElapsedTime()
{
    if(!QueryPerformanceCounter(&m_qpcLastTime))
    {
        throw new std::runtime_error("");
    }

    m_leftOverTicks         = 0;
    m_framesPerSecond       = 0;
    m_framesThisSecond      = 0;
    m_qpcSecondCounter      = 0;
}
