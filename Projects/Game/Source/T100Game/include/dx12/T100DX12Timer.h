#ifndef T100DX12TIMER_H
#define T100DX12TIMER_H

#include <windows.h>

class T100DX12Timer
{
    public:
        T100DX12Timer();
        virtual ~T100DX12Timer();

        UINT64                  GetElapsedTicks() const;
        double                  GetElapsedSeconds() const;

        UINT64                  GetTotalTicks() const;
        double                  GetTotalSeconds() const;

        UINT32                  GetFrameCount() const;

        UINT32                  GetFramesPerSecond() const;

        void                    SetFixedTimeStep(bool isFiexedTimeStep);

        void                    SetTargetElapsedTicks(UINT64 targetElapsed);
        void                    SetTargetElapsedSeconds(double targetElapsed);

        static const UINT64 TicksPerSecond = 10000000;

        static double           TicksToSeconds(UINT64 ticks);
        static UINT64           SecondsToTicks(double seconds);

        void                    ResetElapsedTime();

        typedef void(*LPUPDATEFUNC) (void);

        void                    Tick(LPUPDATEFUNC update = nullptr);

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

#endif // T100DX12TIMER_H
