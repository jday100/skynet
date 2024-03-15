#ifndef T100THREADTASK_H
#define T100THREADTASK_H

#include "T100Task.h"


class T100ThreadTask : public T100Task
{
    public:
        T100ThreadTask();
        virtual ~T100ThreadTask();

        virtual T100BOOL            run(T100VOID* = T100NULL) = 0;

    protected:

    private:
};

#endif // T100THREADTASK_H
