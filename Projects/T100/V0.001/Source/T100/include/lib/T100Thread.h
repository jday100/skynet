#ifndef T100THREAD_H
#define T100THREAD_H

#include <thread>
#include "T100Common.h"


class T100Thread
{
    public:
        T100Thread();
        virtual ~T100Thread();

        T100BOOL                start();
        T100BOOL                stop();

        T100BOOL                wait();
        T100BOOL                detach();
        T100BOOL                sleep();
        T100BOOL                wakeup();

    protected:
        virtual T100BOOL        run();

    private:
        std::thread*            m_thread    = T100NULL;
};

#endif // T100THREAD_H
