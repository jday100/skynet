#ifndef T100SPACEGEOMETRY_H
#define T100SPACEGEOMETRY_H

#include "T100Matrix3.h"

class T100SpaceGeometry
{
    public:
        T100SpaceGeometry();
        virtual ~T100SpaceGeometry();

        static T100Matrix3          Translate(T100FLOAT, T100FLOAT, T100FLOAT);
        static T100Matrix3          RevolveX(T100FLOAT);
        static T100Matrix3          RevolveY(T100FLOAT);
        static T100Matrix3          RevolveZ(T100FLOAT);

    protected:

    private:
};

#endif // T100SPACEGEOMETRY_H
