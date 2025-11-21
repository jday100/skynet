#ifndef T100VECTOR2F_H
#define T100VECTOR2F_H

#include "T100Common.h"

class T100Vector2f
{
    public:
        T100Vector2f();
        T100Vector2f(T100FLOAT, T100FLOAT);
        virtual ~T100Vector2f();

        union{
            struct{
                T100FLOAT   X;
                T100FLOAT   Y;
            };
            T100FLOAT       FLOAT2[2];
        };

        T100Vector2f        operator+(T100Vector2f&);
        T100Vector2f        operator-(T100Vector2f&);
        T100Vector2f        operator*(T100Vector2f&);
        T100Vector2f        operator/(T100Vector2f&);

    protected:

    private:
};

#endif // T100VECTOR2F_H
