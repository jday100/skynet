#ifndef T100VIEWBASE_H
#define T100VIEWBASE_H

#include "T100Common.h"

class T100ViewBase
{
    public:
        T100ViewBase();
        virtual ~T100ViewBase();

        virtual T100VOID            Draw(T100VOID* = T100NULL) = 0;

    protected:

    private:
};

#endif // T100VIEWBASE_H
