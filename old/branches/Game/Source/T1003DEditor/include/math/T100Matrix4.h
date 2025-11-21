#ifndef T100MATRIX4_H
#define T100MATRIX4_H

#include "T100Common.h"

typedef struct{
    T100FLOAT       FLOAT[4];
}T100FLOAT4;

typedef union{
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
    T100FLOAT4      FLOAT4[4];
    T100FLOAT       FLOAT16[16];
    T100FLOAT       FLOAT4X4[4][4];
}T100FLOAT4X4_UNION;

class T100Matrix4
{
    public:
        T100Matrix4();
        T100Matrix4(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT,
                    T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT,
                    T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT,
                    T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Matrix4();

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
            T100FLOAT4      FLOAT4[4];
            T100FLOAT       FLOAT16[16];
            T100FLOAT       FLOAT4X4[4][4];
        };

        T100Matrix4             operator+(T100Matrix4&);
        T100Matrix4             operator*(T100Matrix4&);

    protected:

    private:
};

#endif // T100MATRIX4_H
