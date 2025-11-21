#ifndef T100VECTOR2U_H
#define T100VECTOR2U_H

#include "T100Common.h"

class T100Vector2u
{
    public:
        T100Vector2u();
        T100Vector2u(T100UINT, T100UINT);
        virtual ~T100Vector2u();

        union{
            struct{
                T100UINT    X;
                T100UINT    Y;
            };
            T100UINT        UINT2[2];
        };

        T100Vector2u        operator+(T100Vector2u&);
        T100Vector2u        operator-(T100Vector2u&);
        T100Vector2u        operator*(T100Vector2u&);
        T100Vector2u        operator/(T100Vector2u&);

    protected:

    private:
};

#endif // T100VECTOR2U_H
