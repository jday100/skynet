#ifndef T100APPLICATIONBASE_H
#define T100APPLICATIONBASE_H

#include "T100Common.h"

class T100ApplicationBase
{
    public:
        T100ApplicationBase();
        virtual ~T100ApplicationBase();

        virtual T100VOID                        Create() = 0;
        virtual T100VOID                        Destroy() = 0;

    protected:

    private:
};

#endif // T100APPLICATIONBASE_H
