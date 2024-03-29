#ifndef T100WXPAINTELEMENTSLOADTHREADTASK_H
#define T100WXPAINTELEMENTSLOADTHREADTASK_H

#include "wx\T100WxThreadTask.h"

class T100WxPaintElementsLoadThreadTask : public T100WxThreadTask
{
    public:
        T100WxPaintElementsLoadThreadTask();
        virtual ~T100WxPaintElementsLoadThreadTask();

        virtual T100VOID            run();

    protected:
        T100VOID                    send(T100VOID*);

    private:
};

#endif // T100WXPAINTELEMENTSLOADTHREADTASK_H
