#ifndef T100PAINTERMENUQUITTHREADTASK_H
#define T100PAINTERMENUQUITTHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuQuitThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuQuitThreadTask();
        virtual ~T100PainterMenuQuitThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100PAINTERMENUQUITTHREADTASK_H
