#ifndef T100MATRIX3_H
#define T100MATRIX3_H

#include "T100Common.h"


typedef struct{
    T100FLOAT       FLOAT[3];
}T100FLOAT3;

typedef union{
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
    T100FLOAT3      FLOAT3[3];
    T100FLOAT       FLOAT9[9];
    T100FLOAT       FLOAT3X3[3][3];
}T100FLOAT3X3_UNION;

class T100Matrix3
{
    public:
        T100Matrix3();
        T100Matrix3(T100FLOAT, T100FLOAT, T100FLOAT,
                    T100FLOAT, T100FLOAT, T100FLOAT,
                    T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Matrix3();

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
            T100FLOAT3      FLOAT3[3];
            T100FLOAT       FLOAT9[9];
            T100FLOAT       FLOAT3X3[3][3];
        };

        T100Matrix3             operator+(T100Matrix3&);
        T100Matrix3             operator*(T100Matrix3&);

    protected:

    private:
};

#endif // T100MATRIX3_H
