#include "T100DX12Timer.h"


T100DX12Timer::T100DX12Timer() :
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
    QueryPerformanceFrequency(&m_qpcFrequency);
    QueryPerformanceCounter(&m_qpcLastTime);

    m_qpcMaxDelta = m_qpcFrequency.QuadPart / 10;
}

T100DX12Timer::~T100DX12Timer()
{
    //dtor
}

UINT64 T100DX12Timer::GetElapsedTicks() const
{
    return m_elapsedTicks;
}

double T100DX12Timer::GetElapsedSeconds() const
{
    return TicksToSeconds(m_elapsedTicks);
}

UINT64 T100DX12Timer::GetTotalTicks() const
{
    return m_totalTicks;
}

double T100DX12Timer::GetTotalSeconds() const
{
    return TicksToSeconds(m_totalTicks);
}

UINT32 T100DX12Timer::GetFrameCount() const
{
    return m_frameCount;
}

UINT32 T100DX12Timer::GetFramesPerSecond() const
{
    return m_framesPerSecond;
}

void T100DX12Timer::SetFixedTimeStep(bool isFixedTimeStep)
{
    m_isFixedTimeStep = isFixedTimeStep;
}

void T100DX12Timer::SetTargetElapsedTicks(UINT64 targetElapsed)
{
    m_targetElapsedTicks = targetElapsed;
}

void T100DX12Timer::SetTargetElapsedSeconds(double targetElapsed)
{
    m_targetElapsedTicks = SecondsToTicks(targetElapsed);
}

double T100DX12Timer::TicksToSeconds(UINT64 ticks)
{
    return static_cast<double>(ticks) / TicksPerSecond;
}

UINT64 T100DX12Timer::SecondsToTicks(double seconds)
{
    return static_cast<UINT64>(seconds * TicksPerSecond);
}

void T100DX12Timer::ResetElapsedTime()
{
    QueryPerformanceCounter(&m_qpcLastTime);

    m_leftOverTicks = 0;
    m_framesPerSecond = 0;
    m_framesThisSecond = 0;
    m_qpcSecondCounter = 0;
}

void T100DX12Timer::Tick(LPUPDATEFUNC update)
{
    LARGE_INTEGER           currentTime;

    QueryPerformanceCounter(&currentTime);

    UINT64 timeDelta = currentTime.QuadPart - m_qpcLastTime.QuadPart;

    m_qpcLastTime = currentTime;
    m_qpcSecondCounter += timeDelta;

    if (timeDelta > m_qpcMaxDelta)
    {
        timeDelta = m_qpcMaxDelta;
    }

    timeDelta *= TicksPerSecond;
    timeDelta /= m_qpcFrequency.QuadPart;

    UINT32 lastFrameCount = m_frameCount;

    if (m_isFixedTimeStep)
    {
        if (abs(static_cast<int>(timeDelta - m_targetElapsedTicks)) < TicksPerSecond / 4000)
        {
            timeDelta = m_targetElapsedTicks;
        }

        m_leftOverTicks += timeDelta;

        while (m_leftOverTicks >= m_targetElapsedTicks)
        {
            m_elapsedTicks = m_targetElapsedTicks;
            m_totalTicks += m_targetElapsedTicks;
            m_leftOverTicks -= m_targetElapsedTicks;
            m_frameCount++;

            if (update)
            {
                update();
            }
        }
    }
    else
    {
        m_elapsedTicks = timeDelta;
        m_totalTicks += timeDelta;
        m_leftOverTicks = 0;
        m_frameCount++;

        if (update)
        {
            update();
        }
    }

    if (m_frameCount != lastFrameCount)
    {
        m_framesThisSecond++;
    }

    if (m_qpcSecondCounter >= static_cast<UINT64>(m_qpcFrequency.QuadPart))
    {
        m_framesPerSecond = m_framesThisSecond;
        m_framesThisSecond = 0;
        m_qpcSecondCounter %= m_qpcFrequency.QuadPart;
    }
}
