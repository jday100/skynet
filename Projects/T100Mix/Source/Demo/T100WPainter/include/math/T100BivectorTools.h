#ifndef T100BIVECTORTOOLS_H
#define T100BIVECTORTOOLS_H

#include "T100Bivector.h"

class T100BivectorTools
{
    public:
        T100BivectorTools();
        virtual ~T100BivectorTools();

        static T100FLOAT            distance(T100Bivector, T100Bivector);

    protected:

    private:
};

#endif // T100BIVECTORTOOLS_H
