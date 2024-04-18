#ifndef T100PAINTERMENUSAVEASTHREADTASK_H
#define T100PAINTERMENUSAVEASTHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuSaveAsThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuSaveAsThreadTask();
        virtual ~T100PainterMenuSaveAsThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100PAINTERMENUSAVEASTHREADTASK_H
