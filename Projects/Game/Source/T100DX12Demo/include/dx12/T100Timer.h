#ifndef T100TIMER_H
#define T100TIMER_H

#include "stdafx.h"

class T100Timer
{
    public:
        T100Timer();
        virtual ~T100Timer();

        UINT64 GetElapsedTicks() const;
        double GetElapsedSeconds() const;

        UINT64 GetTotalTicks() const;
        double GetTotalSeconds() const;

        UINT32 GetFrameCount() const;

        UINT32 GetFramesPerSecond() const;

        void SetFixedTimeStep(bool isFiexedTimeStep);

        void SetTargetElapsedTicks(UINT64 targetElapsed);
        void SetTargetElapsedSeconds(double targetElapsed);

        static const UINT64 TicksPerSecond = 10000000;

        static double TicksToSeconds(UINT64 ticks);
        static UINT64 SecondsToTicks(double seconds);

        void ResetElapsedTime();

        typedef void(*LPUPDATEFUNC) (void);

        void Tick(LPUPDATEFUNC update = nullptr);

    protected:

    private:
    // Source timing data uses QPC units.
    LARGE_INTEGER m_qpcFrequency;
    LARGE_INTEGER m_qpcLastTime;
    UINT64 m_qpcMaxDelta;

    // Derived timing data uses a canonical tick format.
    UINT64 m_elapsedTicks;
    UINT64 m_totalTicks;
    UINT64 m_leftOverTicks;

    // Members for tracking the framerate.
    UINT32 m_frameCount;
    UINT32 m_framesPerSecond;
    UINT32 m_framesThisSecond;
    UINT64 m_qpcSecondCounter;

    // Members for configuring fixed timestep mode.
    bool m_isFixedTimeStep;
    UINT64 m_targetElapsedTicks;
};

#endif // T100TIMER_H
