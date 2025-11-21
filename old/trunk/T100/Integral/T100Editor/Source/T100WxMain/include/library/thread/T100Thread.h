#ifndef T100THREAD_H
#define T100THREAD_H

#include <atomic>
#include <thread>
#include "T100Common.h"

class T100Thread
{
    public:
        T100Thread();
        template<typename _Callable, typename... _Args>
        T100Thread(_Callable&& __f, _Args&&... __args)
        {
            m_thread    = T100NEW std::thread(std::forward<_Callable>(__f),
                     std::forward<_Args>(__args)...);
            m_running   = T100TRUE;
        }
        virtual ~T100Thread();

        virtual T100VOID            Start();
        virtual T100VOID            Stop();

        virtual T100VOID            Detach();
        virtual T100VOID            Waiting();

        T100BOOL                    IsRunning();

        static T100VOID             Sleep(T100UINT32);

    protected:
        virtual T100VOID            Run();

    private:
        std::atomic_bool            m_running;
        std::thread*                m_thread        = T100NULL;

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100THREAD_H
