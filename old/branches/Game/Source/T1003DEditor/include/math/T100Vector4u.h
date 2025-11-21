#ifndef T100VECTOR4U_H
#define T100VECTOR4U_H

#include "T100Common.h"

class T100Vector4u
{
    public:
        T100Vector4u();
        T100Vector4u(T100UINT, T100UINT, T100UINT, T100UINT);
        virtual ~T100Vector4u();

        union{
            struct{
                T100UINT    X;
                T100UINT    Y;
                T100UINT    Z;
                T100UINT    W;
            };
            struct{
                T100UINT    RED;
                T100UINT    GREEN;
                T100UINT    BLUE;
                T100UINT    ALPHA;
            };
            T100UINT        UINT4[4];
        };

    protected:

    private:
};

#endif // T100VECTOR4U_H
