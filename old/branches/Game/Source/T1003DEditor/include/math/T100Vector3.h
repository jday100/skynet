#ifndef T100VECTOR3_H
#define T100VECTOR3_H

#include "T100Common.h"

typedef union{
    struct{
        T100FLOAT   X;
        T100FLOAT   Y;
        T100FLOAT   Z;
    };
    T100FLOAT       FLOAT3[3];
}T100FLOAT3_UNION;

class T100Vector3
{
    public:
        T100Vector3();
        T100Vector3(T100FLOAT, T100FLOAT, T100FLOAT);
        virtual ~T100Vector3();

        union{
            struct{
                T100FLOAT   X;
                T100FLOAT   Y;
                T100FLOAT   Z;
            };
            T100FLOAT       FLOAT3[3];
        };

        T100Vector3             operator+(T100Vector3&);
        T100Vector3             operator*(T100Vector3&);

    protected:


    private:
};

#endif // T100VECTOR3_H
