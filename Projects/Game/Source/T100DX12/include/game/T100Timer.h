#ifndef T100TIMER_H
#define T100TIMER_H

#include <windows.h>

#include "T100Common.h"
#include "T100DX12Helper.h"

class T100Timer
{
    public:
        T100Timer();
        virtual ~T100Timer();

        UINT64                      GetElapsedTicks() const;
        DOUBLE                      GetElapsedSeconds() const;

        UINT64                      GetTotalTicks() const;
        DOUBLE                      GetTotalSeconds() const;

        UINT32                      GetFrameCount() const;

        UINT32                      GetFramesPerSecond() const;

        T100VOID                    SetFixedTimeStep(T100BOOL isFixedTimeStep);

        T100VOID                    SetTargetElapsedTicks(UINT64 targetElapsed);
        T100VOID                    SetTargetElapsedSeconds(DOUBLE targetElapsed);

        static const UINT64         TicksPerSecond          = 10000000;

        static DOUBLE               TicksToSeconds(UINT64 ticks);
        static UINT64               SecondsToTicks(DOUBLE seconds);

        T100VOID                    ResetElapsedTime();


        template<typename TUpdate>
        void Tick(const TUpdate& update)
        {
            LARGE_INTEGER       currentTime;

            if(!QueryPerformanceCounter(&currentTime))
            {
                throw new std::runtime_error("");
            }

            UINT64 timeDelta = currentTime.QuadPart - m_qpcLastTime.QuadPart;

            m_qpcLastTime   = currentTime;
            m_qpcSecondCounter  += timeDelta;

            if(timeDelta > m_qpcMaxDelta)
            {
                timeDelta = m_qpcMaxDelta;
            }

            timeDelta *= TicksPerSecond;
            timeDelta /= m_qpcFrequency.QuadPart;

            UINT32 lastFrameCount = m_frameCount;

            if(m_isFixedTimeStep)
            {
                if(abs(static_cast<INT64>(timeDelta - m_targetElapsedTicks)) < TicksPerSecond / 4000)
                {
                    timeDelta = m_targetElapsedTicks;
                }

                m_leftOverTicks += timeDelta;

                while(m_leftOverTicks >= m_targetElapsedTicks)
                {
                    m_elapsedTicks  = m_targetElapsedTicks;
                    m_totalTicks    += m_targetElapsedTicks;
                    m_leftOverTicks -= m_targetElapsedTicks;
                    m_frameCount++;

                    update();
                }
            }
            else
            {
                m_elapsedTicks  = timeDelta;
                m_totalTicks    += timeDelta;
                m_leftOverTicks = 0;
                m_frameCount++;

                update();
            }

            if(m_frameCount != lastFrameCount)
            {
                m_framesThisSecond++;
            }

            if(m_qpcSecondCounter >= static_cast<UINT64>(m_qpcFrequency.QuadPart))
            {
                m_framesPerSecond   = m_framesThisSecond;
                m_framesThisSecond  = 0;
                m_qpcSecondCounter  %= m_qpcFrequency.QuadPart;
            }
        }

    protected:

    private:
        LARGE_INTEGER           m_qpcFrequency;
        LARGE_INTEGER           m_qpcLastTime;
        UINT64                  m_qpcMaxDelta;

        UINT64                  m_elapsedTicks;
        UINT64                  m_totalTicks;
        UINT64                  m_leftOverTicks;

        UINT32                  m_frameCount;
        UINT32                  m_framesPerSecond;
        UINT32                  m_framesThisSecond;
        UINT64                  m_qpcSecondCounter;

        bool                    m_isFixedTimeStep;
        UINT64                  m_targetElapsedTicks;
};

#endif // T100TIMER_H
