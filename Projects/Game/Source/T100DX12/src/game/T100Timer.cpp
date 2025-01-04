#include "T100Timer.h"

T100Timer::T100Timer()
    :m_elapsedTicks(0),
    m_totalTicks(0),
    m_leftOverTicks(0),
    m_frameCount(0),
    m_framesPerSecond(0),
    m_framesThisSecond(0),
    m_qpcSecondCounter(0),
    m_isFixedTimeStep(false),
    m_targetElapedTicks(TicksPerSecond / 60)
{
    //ctor

    QueryPerformanceFrequency(&m_qpcFrequency);
    QueryPerformanceCounter(&m_qpcLastTime);

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

double T100Timer::GetElapsedSeconds() const
{
    return TicksToSeconds(m_elapsedTicks);
}

UINT64 T100Timer::GetTotalTicks() const
{
    return m_totalTicks;
}

double T100Timer::GetTotalSeconds() const
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

void T100Timer:SetFixedTimeStep(bool isFixedTimeStep)
{
    m_isFixedTimeStep = isFixedTimestep;
}

void T100Timer::SetTargetElapsedTicks(UINT64 targetElapsed)
{
    m_targetElapsedTicks = targetElapsed;
}

void T100Timer::SetTargetElapsedSeconds(double targetElapsed)
{
    m_targetElapsedTicks = SecondsToTicks(targetElapsed);
}

double T100Timer::TicksToSeconds(UINT64 ticks)
{
    return static_cast<double>(ticks) / TicksPerSecond;
}

UINT64 T100Timer::SecondsToTicks(double seconds)
{
    return static_cast<UINT64>(seconds * TicksPerSecond);
}

void T100Timer::ResetElapsedTime()
{
    QueryPerformanceCounter(&m_qpcLastTime);

    m_leftOverTicks         = 0;
    m_framesPerSecond       = 0;
    m_framesThisSecond      = 0;
    m_qpcSecondCounter      = 0;
}

void T100Timer::Tick(LPUPDATEFUNC update)
{
    LARGE_INTEGER currentTime;

    QueryPerformanceCounter(&currentTime);

    UINT64 timeDelta = currentTime.QuadPart - m_qpcLastTime.QuadPart;

    m_qpcLastTime = currentTime;
    m_qpcSecondCounter += timeDelta;

    // Clamp excessively large time deltas (e.g. after paused in the debugger).
    if (timeDelta > m_qpcMaxDelta)
    {
        timeDelta = m_qpcMaxDelta;
    }

    // Convert QPC units into a canonical tick format. This cannot overflow due to the previous clamp.
    timeDelta *= TicksPerSecond;
    timeDelta /= m_qpcFrequency.QuadPart;

    UINT32 lastFrameCount = m_frameCount;

    if (m_isFixedTimeStep)
    {
        // Fixed timestep update logic

        // If the app is running very close to the target elapsed time (within 1/4 of a millisecond) just clamp
        // the clock to exactly match the target value. This prevents tiny and irrelevant errors
        // from accumulating over time. Without this clamping, a game that requested a 60 fps
        // fixed update, running with vsync enabled on a 59.94 NTSC display, would eventually
        // accumulate enough tiny errors that it would drop a frame. It is better to just round
        // small deviations down to zero to leave things running smoothly.

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
        // Variable timestep update logic.
        m_elapsedTicks = timeDelta;
        m_totalTicks += timeDelta;
        m_leftOverTicks = 0;
        m_frameCount++;

        if (update)
        {
            update();
        }
    }

    // Track the current framerate.
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
