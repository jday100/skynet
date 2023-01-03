#ifndef T100PLANIMETRY_H
#define T100PLANIMETRY_H

#include "T100Common.h"

namespace T100Math{

class T100Planimetry
{
    public:
        T100Planimetry();
        virtual ~T100Planimetry();

        static T100FLOAT            Dist(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);

        static T100BOOL             Hit(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);

    protected:

    private:
};

}

#endif // T100PLANIMETRY_H
