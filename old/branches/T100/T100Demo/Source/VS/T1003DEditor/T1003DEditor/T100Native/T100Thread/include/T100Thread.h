#ifndef T100THREAD_H
#define T100THREAD_H

#include <atomic>
#include <thread>
#include <condition_variable>
#include "T100Common.h"

class T100Thread
{
    public:
        T100Thread();
        virtual ~T100Thread();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Waiting();

    protected:
        std::atomic_bool            m_running;
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;
        std::thread*                m_thread        = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
        virtual T100VOID            run();
};

#endif // T100THREAD_H
