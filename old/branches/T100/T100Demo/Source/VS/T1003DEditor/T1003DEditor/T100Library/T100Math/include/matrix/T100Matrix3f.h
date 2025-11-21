#ifndef T100MATRIX3F_H
#define T100MATRIX3F_H

#include "T100Common.h"

class T100Matrix3f
{
    public:
        T100Matrix3f();
        T100Matrix3f(T100FLOAT, T100FLOAT, T100FLOAT,
                     T100FLOAT, T100FLOAT, T100FLOAT,
                     T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Matrix3f();

        union{
            struct{
                T100FLOAT   _11;
                T100FLOAT   _12;
                T100FLOAT   _13;

                T100FLOAT   _21;
                T100FLOAT   _22;
                T100FLOAT   _23;

                T100FLOAT   _31;
                T100FLOAT   _32;
                T100FLOAT   _33;
            };
            T100FLOAT       FLOAT9[9];
            T100FLOAT       FLOAT3X3[3][3];
        };

        T100Matrix3f        operator+(T100Matrix3f&);
        T100Matrix3f        operator-(T100Matrix3f&);
        T100Matrix3f        operator*(T100Matrix3f&);
        T100Matrix3f        operator/(T100Matrix3f&);

    protected:

    private:
};

#endif // T100MATRIX3F_H
