#ifndef T100WXPAINTFILELOADTHREADTASK_H
#define T100WXPAINTFILELOADTHREADTASK_H

#include "wx\T100WxThreadTask.h"


class T100WxPaintFileLoadThreadTask : public T100WxThreadTask
{
    public:
        T100WxPaintFileLoadThreadTask();
        virtual ~T100WxPaintFileLoadThreadTask();

        virtual T100VOID            run();

    protected:

    private:
};

#endif // T100WXPAINTFILELOADTHREADTASK_H
