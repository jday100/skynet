#ifndef T100VECTOR4_H
#define T100VECTOR4_H

#include "T100Common.h"

typedef union{
    struct{
        T100FLOAT   X;
        T100FLOAT   Y;
        T100FLOAT   Z;
        T100FLOAT   W;
    };
    struct{
        T100FLOAT   RED;
        T100FLOAT   GREEN;
        T100FLOAT   BLUE;
        T100FLOAT   ALPHA;
    };
    T100FLOAT       FLOAT4[4];
}T100FLOAT4_UNION;

class T100Vector4
{
    public:
        T100Vector4();
        T100Vector4(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Vector4();

        union{
            struct{
                T100FLOAT   X;
                T100FLOAT   Y;
                T100FLOAT   Z;
                T100FLOAT   W;
            };
            struct{
                T100FLOAT   RED;
                T100FLOAT   GREEN;
                T100FLOAT   BLUE;
                T100FLOAT   ALPHA;
            };
            T100FLOAT       FLOAT4[4];
        };

        T100Vector4             operator+(T100Vector4&);
        T100Vector4             operator*(T100Vector4&);

    protected:

    private:
};

#endif // T100VECTOR4_H
