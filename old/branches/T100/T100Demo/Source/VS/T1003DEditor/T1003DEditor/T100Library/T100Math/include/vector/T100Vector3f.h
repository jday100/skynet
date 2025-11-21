#ifndef T100VECTOR3F_H
#define T100VECTOR3F_H

#include "T100Common.h"

class T100Vector3f
{
    public:
        T100Vector3f();
        T100Vector3f(T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Vector3f();

        union{
            struct{
                T100FLOAT       X;
                T100FLOAT       Y;
                T100FLOAT       Z;
            };
            T100FLOAT           FLOAT3[3];
        };

        T100Vector3f            operator+(T100Vector3f&);
        T100Vector3f            operator-(T100Vector3f&);
        T100Vector3f            operator*(T100Vector3f&);
        T100Vector3f            operator/(T100Vector3f&);

        T100Vector3f            operator*(T100FLOAT);
        T100Vector3f            operator/(T100FLOAT);

        T100FLOAT               Norm();

    protected:

    private:
};

#endif // T100VECTOR3F_H
