#ifndef T100PAINTERMENUOPENTHREADTASK_H
#define T100PAINTERMENUOPENTHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuOpenThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuOpenThreadTask();
        virtual ~T100PainterMenuOpenThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100PAINTERMENUOPENTHREADTASK_H
