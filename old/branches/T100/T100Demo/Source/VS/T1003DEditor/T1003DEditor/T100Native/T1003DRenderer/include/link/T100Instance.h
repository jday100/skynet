#ifndef T100INSTANCE_H
#define T100INSTANCE_H

#include "T1003DObject.h"

class T100Instance : public T1003DObject
{
    public:
        T100Instance();
        virtual ~T100Instance();

        virtual T100VOID            Clear() = 0;

    protected:

    private:
};

#endif // T100INSTANCE_H
