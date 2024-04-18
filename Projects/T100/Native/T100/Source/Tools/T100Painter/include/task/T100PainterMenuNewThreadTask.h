#ifndef T100PAINTERMENUNEWTHREADTASK_H
#define T100PAINTERMENUNEWTHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuNewThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuNewThreadTask();
        virtual ~T100PainterMenuNewThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100PAINTERMENUNEWTHREADTASK_H
