#ifndef T100PAINTERMENUSAVETHREADTASK_H
#define T100PAINTERMENUSAVETHREADTASK_H

#include "T100WxThreadTask.h"

class T100PainterMenuSaveThreadTask : public T100WxThreadTask
{
    public:
        T100PainterMenuSaveThreadTask();
        virtual ~T100PainterMenuSaveThreadTask();

    protected:
        T100VOID                        run();

    private:
};

#endif // T100PAINTERMENUSAVETHREADTASK_H
