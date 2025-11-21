#ifndef T100VECTOR4F_H
#define T100VECTOR4F_H

#include "T100Common.h"

class T100Vector4f
{
    public:
        T100Vector4f();
        T100Vector4f(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Vector4f();

        union{
            struct{
                T100FLOAT       X;
                T100FLOAT       Y;
                T100FLOAT       Z;
                T100FLOAT       W;
            };
            T100FLOAT           FLOAT4[4];
        };

        T100Vector4f            operator+(T100Vector4f&);
        T100Vector4f            operator-(T100Vector4f&);
        T100Vector4f            operator*(T100Vector4f&);
        T100Vector4f            operator/(T100Vector4f&);

    protected:

    private:
};

#endif // T100VECTOR4F_H
