#ifndef T100MATRIX3_H
#define T100MATRIX3_H

#include "T100Common.h"

typedef struct{
    T100FLOAT       X;
    T100FLOAT       Y;
    T100FLOAT       Z;
}T100POINT;

typedef union{
    T100FLOAT       DATA[9];
    struct{
        T100POINT   X;
        T100POINT   Y;
        T100POINT   Z;
    };
}T100FACET;

class T100Matrix3
{
    public:
        T100Matrix3();
        virtual ~T100Matrix3();

        T100FACET       DATA;

    protected:

    private:
};

#endif // T100MATRIX3_H
