#include "data/T100DX12Timer.h"

T100DX12Timer::T100DX12Timer() :
    T1003DTimer()
{
    //ctor
    init();
}

T100DX12Timer::~T100DX12Timer()
{
    //dtor
    uninit();
}

T100VOID T100DX12Timer::init()
{
    QueryPerformanceFrequency(&m_qpcFrequency);
    QueryPerformanceCounter(&m_qpcLastTime);

    m_qpcMaxDelta   = m_qpcFrequency.QuadPart / 10;
}

T100VOID T100DX12Timer::uninit()
{

}

T100UINT32 T100DX12Timer::GetFramesPerSecond() const
{
    return m_framesPerSecond;
}

T100VOID T100DX12Timer::Tick()
{
    LARGE_INTEGER       currentTime;

    QueryPerformanceCounter(&currentTime);

    T100UINT64          timeDelta;

    timeDelta           = currentTime.QuadPart - m_qpcLastTime.QuadPart;

    m_qpcLastTime       = currentTime;
    m_qpcSecondCounter  += timeDelta;

    if(timeDelta > m_qpcMaxDelta){
        timeDelta   = m_qpcMaxDelta;
    }

    timeDelta   *= TicksPerSecond;
    timeDelta   /= m_qpcFrequency.QuadPart;

    T100UINT32  lastFrameCount  = m_frameCount;

    if(m_isFixedTimeStep){
        if(abs(static_cast<int>(timeDelta - m_targetElapsedTicks)) < TicksPerSecond / 4000){
            timeDelta   = m_targetElapsedTicks;
        }

        m_leftOverTicks     += timeDelta;

        while(m_leftOverTicks >= m_targetElapsedTicks){
            m_elapsedTicks  = m_targetElapsedTicks;
            m_totalTicks    += m_targetElapsedTicks;
            m_leftOverTicks -= m_targetElapsedTicks;
            m_frameCount++;
        }

    }else{
        m_elapsedTicks  = timeDelta;
        m_totalTicks    += timeDelta;
        m_leftOverTicks = 0;
        m_frameCount++;
    }

    if(m_frameCount != lastFrameCount){
        m_framesThisSecond++;
    }

    if(m_qpcSecondCounter >= static_cast<T100UINT64>(m_qpcFrequency.QuadPart)){
        m_framesPerSecond   = m_framesThisSecond;
        m_framesThisSecond  = 0;
        m_qpcSecondCounter  %= m_qpcFrequency.QuadPart;
    }
}
