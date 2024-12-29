#ifndef T100LOADTASK_H
#define T100LOADTASK_H

#include "T100WxThreadTask.h"

class T100LoadTask : public T100WxThreadTask
{
    public:
        T100LoadTask();
        virtual ~T100LoadTask();

    protected:
        T100VOID                run();

    private:
};

#endif // T100LOADTASK_H
