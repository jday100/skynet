#ifndef T100VECTOR3U_H
#define T100VECTOR3U_H

#include "T100Common.h"

class T100Vector3u
{
    public:
        T100Vector3u();
        T100Vector3u(T100UINT, T100UINT, T100UINT);
        virtual ~T100Vector3u();

        union{
            struct{
                T100UINT    X;
                T100UINT    Y;
                T100UINT    Z;
            };
            T100UINT       UINT3[3];
        };

    protected:

    private:
};

#endif // T100VECTOR3U_H
