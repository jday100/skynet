#ifndef T100WPAINTERMENUOPENTHREADTASK_H
#define T100WPAINTERMENUOPENTHREADTASK_H

#include "T100WxThreadTask.h"


class T100WPainterMenuOpenThreadTask : public T100WxThreadTask
{
    public:
        T100WPainterMenuOpenThreadTask();
        virtual ~T100WPainterMenuOpenThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100WPAINTERMENUOPENTHREADTASK_H
