#ifndef T100MATRIX4_H
#define T100MATRIX4_H

#include "T100Common.h"

typedef union{
    T100FLOAT           DATA16[16];
    T100FLOAT           DATA4[4][4];
}T100MATRIX4;

class T100Matrix4;

T100Matrix4         operator *  (const T100Matrix4&, const T100Matrix4&);

class T100Matrix4
{
    public:
        T100Matrix4();
        virtual ~T100Matrix4();

        T100MATRIX4     DATA;

    protected:

    private:
        T100VOID        TurnOn();
        T100VOID        TurnOff();
};

#endif // T100MATRIX4_H
