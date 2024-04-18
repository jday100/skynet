#ifndef T100BIVECTOR_H
#define T100BIVECTOR_H

#include "T100Common.h"

class T100Bivector
{
    public:
        T100Bivector();
        T100Bivector(T100FLOAT, T100FLOAT);
        virtual ~T100Bivector();

        T100FLOAT           X;
        T100FLOAT           Y;

    protected:

    private:
};

#endif // T100BIVECTOR_H
