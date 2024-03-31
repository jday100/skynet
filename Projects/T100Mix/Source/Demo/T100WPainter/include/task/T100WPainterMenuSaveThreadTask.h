#ifndef T100WPAINTERMENUSAVETHREADTASK_H
#define T100WPAINTERMENUSAVETHREADTASK_H

#include "T100WxThreadTask.h"


class T100WPainterMenuSaveThreadTask : public T100WxThreadTask
{
    public:
        T100WPainterMenuSaveThreadTask();
        virtual ~T100WPainterMenuSaveThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100WPAINTERMENUSAVETHREADTASK_H
