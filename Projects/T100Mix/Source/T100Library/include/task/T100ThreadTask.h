#ifndef T100THREADTASK_H
#define T100THREADTASK_H

#include <atomic>
#include <thread>
#include "T100Task.h"


class T100ThreadTask : public T100Task
{
    public:
        T100ThreadTask();
        virtual ~T100ThreadTask();

        T100BOOL                    start();
        T100BOOL                    stop();

        T100BOOL                    running();

        virtual T100BOOL            run(T100VOID* = T100NULL) = 0;

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        std::atomic_bool            m_running;
        std::thread*                m_thread            = T100NULL;
};

#endif // T100THREADTASK_H
