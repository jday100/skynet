#ifndef T100THREADCOMMON_H
#define T100THREADCOMMON_H

#include "T100Thread.h"


class T100ThreadCommon : public T100Thread
{
    public:
        T100ThreadCommon();
        virtual ~T100ThreadCommon();

        T100BOOL                ok();

    protected:
        T100BOOL                run();

    private:
        T100BOOL                result;
};

#endif // T100THREADCOMMON_H
