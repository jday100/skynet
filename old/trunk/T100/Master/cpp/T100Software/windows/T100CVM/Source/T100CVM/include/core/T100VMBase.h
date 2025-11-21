#ifndef T100VMBASE_H
#define T100VMBASE_H

#include "T100Common.h"

using namespace T100LIBRARY;

class T100VMBase
{
    public:
        T100VMBase();
        virtual ~T100VMBase();

        virtual T100VOID            Start() = 0;
        virtual T100VOID            Stop() = 0;

    protected:

    private:
};

#endif // T100VMBASE_H
