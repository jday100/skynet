#ifndef T100THREAD_H
#define T100THREAD_H

#include <atomic>
#include <thread>
#include "T100Common.h"
#include "T100Class.h"

class T100Thread : public T100Class
{
    public:
        T100Thread();
        template<typename _Callable, typename... _Args>
        T100Thread(_Callable&& __f, _Args&&... __args)
        {
            m_threadPtr = T100NEW std::thread(std::forward<_Callable>(__f),
                     std::forward<_Args>(__args)...);
            m_running   = T100TRUE;
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
