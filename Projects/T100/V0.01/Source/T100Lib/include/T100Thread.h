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

        T100BOOL                start();
        T100BOOL                stop();

        T100BOOL                running();

        T100BOOL                detach();

        T100BOOL                hangup();
        T100BOOL                wait();
        T100BOOL                wakeup();

        static T100VOID         sleep(T100WORD);

    protected:
        T100VOID                create();
        T100VOID                destroy();

        virtual T100VOID        run();

    private:
        std::atomic_bool        m_running;
        std::thread*            m_thread            = T100NULL;

};

#endif // T100THREAD_H
