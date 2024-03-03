#ifndef T100WXTASK_H
#define T100WXTASK_H

#include "T100Common.h"


class T100WXTask
{
    public:
        T100WXTask();
        virtual ~T100WXTask();

        virtual T100BOOL            run() = 0;

    protected:

    private:
};

#endif // T100WXTASK_H
