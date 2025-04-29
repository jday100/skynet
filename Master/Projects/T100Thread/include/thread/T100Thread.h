#ifndef T100THREAD_H
#define T100THREAD_H

#include <atomic>
#include <thread>
#include "T100Common.h"

class T100Thread
{
    public:
        T100Thread();
        virtual ~T100Thread();

        T100VOID                    Start();
        T100VOID                    Stop();

        T100BOOL                    IsRunning();

        T100VOID                    Detach();

        T100VOID                    Waiting();

        static T100VOID             Sleep(T100WORD);

    protected:
        virtual T100VOID            Run();

    private:
        std::atomic_bool            m_running;
        std::thread*                m_threadPtr         = T100NULL;

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100THREAD_H
