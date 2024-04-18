#ifndef T100PAINTERMENUCLOSETHREADTASK_H
#define T100PAINTERMENUCLOSETHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuCloseThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuCloseThreadTask();
        virtual ~T100PainterMenuCloseThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100PAINTERMENUCLOSETHREADTASK_H
