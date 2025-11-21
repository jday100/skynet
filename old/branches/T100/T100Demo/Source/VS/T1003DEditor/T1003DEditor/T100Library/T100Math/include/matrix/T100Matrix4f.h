#ifndef T100MATRIX4F_H
#define T100MATRIX4F_H

#include "T100Common.h"

class T100Matrix4f
{
    public:
        T100Matrix4f();
        T100Matrix4f(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT,
                     T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT,
                     T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT,
                     T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Matrix4f();

        union{
            struct{
                T100FLOAT   _11;
                T100FLOAT   _12;
                T100FLOAT   _13;
                T100FLOAT   _14;

                T100FLOAT   _21;
                T100FLOAT   _22;
                T100FLOAT   _23;
                T100FLOAT   _24;

                T100FLOAT   _31;
                T100FLOAT   _32;
                T100FLOAT   _33;
                T100FLOAT   _34;

                T100FLOAT   _41;
                T100FLOAT   _42;
                T100FLOAT   _43;
                T100FLOAT   _44;
            };
            T100FLOAT       FLOAT16[16];
            T100FLOAT       FLOAT4X4[4][4];
        };

        T100Matrix4f        operator+(T100Matrix4f&);
        T100Matrix4f        operator-(T100Matrix4f&);
        T100Matrix4f        operator*(T100Matrix4f&);
        T100Matrix4f        operator/(T100Matrix4f&);

    protected:

    private:
};

#endif // T100MATRIX4F_H
