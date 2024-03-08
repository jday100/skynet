#ifndef T100TASK_H
#define T100TASK_H

#include "T100Common.h"

namespace T100Library{

class T100Task
{
    public:
        T100Task();
        virtual ~T100Task();

        virtual T100VOID            run() = 0;

    protected:

    private:
};

}

#endif // T100TASK_H
