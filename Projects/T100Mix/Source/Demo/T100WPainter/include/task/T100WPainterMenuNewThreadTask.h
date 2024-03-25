#ifndef T100WPAINTERMENUNEWTHREADTASK_H
#define T100WPAINTERMENUNEWTHREADTASK_H

#include "T100WxThreadTask.h"


class T100WPainterMenuNewThreadTask : public T100WxThreadTask
{
    public:
        T100WPainterMenuNewThreadTask();
        virtual ~T100WPainterMenuNewThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100WPAINTERMENUNEWTHREADTASK_H
