#ifndef T100DX12TIMER_H
#define T100DX12TIMER_H

#include <windows.h>
#include "link/T1003DTimer.h"

class T100DX12Timer : public T1003DTimer
{
    public:
        T100DX12Timer();
        virtual ~T100DX12Timer();

        static const T100UINT64     TicksPerSecond = 10000000;


        T100VOID                    Tick();

        T100UINT32                  GetFramesPerSecond() const;

    protected:
        LARGE_INTEGER               m_qpcFrequency;
        LARGE_INTEGER               m_qpcLastTime;
        T100UINT64                  m_qpcMaxDelta           = 0;

        T100UINT64                  m_elapsedTicks          = 0;
        T100UINT64                  m_totalTicks            = 0;
        T100UINT64                  m_leftOverTicks         = 0;

        T100UINT32                  m_frameCount            = 0;
        T100UINT32                  m_framesPerSecond       = 0;
        T100UINT32                  m_framesThisSecond      = 0;
        T100UINT64                  m_qpcSecondCounter      = 0;

        T100BOOL                    m_isFixedTimeStep       = T100FALSE;
        T100UINT64                  m_targetElapsedTicks    = 0;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100DX12TIMER_H
