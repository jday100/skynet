#ifndef T100WPAINTERMENUSAVEASTHREADTASK_H
#define T100WPAINTERMENUSAVEASTHREADTASK_H

#include "T100WxThreadTask.h"


class T100WPainterMenuSaveAsThreadTask : public T100WxThreadTask
{
    public:
        T100WPainterMenuSaveAsThreadTask();
        virtual ~T100WPainterMenuSaveAsThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100WPAINTERMENUSAVEASTHREADTASK_H
