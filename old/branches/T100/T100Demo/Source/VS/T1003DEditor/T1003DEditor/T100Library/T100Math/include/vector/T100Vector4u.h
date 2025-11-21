#ifndef T100VECTOR4U_H
#define T100VECTOR4U_H

#include "T100Common.h"

class T100Vector4u
{
    public:
        T100Vector4u();
        T100Vector4u(T100UINT8, T100UINT8, T100UINT8, T100UINT8);
        virtual ~T100Vector4u();

        union{
            struct{
                T100UINT8       RED;
                T100UINT8       GREEN;
                T100UINT8       BLUE;
                T100UINT8       ALPHA;
            };
            T100UINT8           UINT4[4];
            T100UINT            UINT;
        };

        T100Vector4u            operator+(T100Vector4u&);
        T100Vector4u            operator-(T100Vector4u&);
        T100Vector4u            operator*(T100Vector4u&);
        T100Vector4u            operator/(T100Vector4u&);

    protected:

    private:
};

#endif // T100VECTOR4U_H
