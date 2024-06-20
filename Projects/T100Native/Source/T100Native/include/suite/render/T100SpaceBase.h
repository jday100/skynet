#ifndef T100SPACEBASE_H
#define T100SPACEBASE_H

#include "T100Point.h"

class T100SpaceBase
{
    public:
        T100SpaceBase();
        virtual ~T100SpaceBase();

        virtual T100Point           Translate(T100Point&, T100FLOAT, T100FLOAT, T100FLOAT) = 0;
        virtual T100Point           RevolveX(T100Point&, T100FLOAT) = 0;
        virtual T100Point           RevolveY(T100Point&, T100FLOAT) = 0;
        virtual T100Point           RevolveZ(T100Point&, T100FLOAT) = 0;

    protected:

    private:
};

#endif // T100SPACEBASE_H
