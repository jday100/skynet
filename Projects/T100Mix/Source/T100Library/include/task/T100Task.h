#ifndef T100TASK_H
#define T100TASK_H

#include "T100Common.h"


class T100Task
{
    public:
        T100Task();
        virtual ~T100Task();

        virtual T100BOOL            run(T100VOID* = T100NULL) = 0;

    protected:

    private:
};

#endif // T100TASK_H
