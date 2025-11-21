#ifndef T100GAMETHREAD_H
#define T100GAMETHREAD_H

#include <atomic>
#include <thread>
#include <condition_variable>
#include "T100Common.h"
#include "game/T100Game.h"

class T100GameThread
{
    public:
        T100GameThread();
        virtual ~T100GameThread();

        T100Game*                   GetGame();

        T100VOID                    Create(HWND, T100UINT, T100UINT);
        T100VOID                    Destroy();

        T100VOID                    Start();
        T100VOID                    Stop();
        T100VOID                    Waiting();

    protected:
        T100Game*                   m_game          = T100NULL;

    private:
        std::atomic_bool            m_running;
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;
        std::thread*                m_thread        = T100NULL;

        T100VOID                    init();
        T100VOID                    uninit();
        T100VOID                    run();
};

#endif // T100GAMETHREAD_H
