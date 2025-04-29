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
            /*
            #ifdef GTHR_ACTIVE_PROXY
                // Create a reference to pthread_create, not just the gthr weak symbol.
                auto __depend = reinterpret_cast<void(*)()>(&pthread_create);
            #else
                auto __depend = nullptr;
            #endif
            */
            m_threadPtr = T100NEW std::thread(std::forward<_Callable>(__f),
                     std::forward<_Args>(__args)...);
        }
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
