#ifndef T100THREADTASK_H
#define T100THREADTASK_H

#include <thread>
#include <functional>
#include "T100Common.h"

class T100ThreadTask
{
    public:
        T100ThreadTask();
        virtual ~T100ThreadTask();

        T100VOID                    start();
        T100VOID                    stop();

    protected:
        virtual T100VOID            run() = 0;

    private:
        std::function<void()>       m_method;
        std::thread*                m_thread            = T100NULL;
};

#endif // T100THREADTASK_H
