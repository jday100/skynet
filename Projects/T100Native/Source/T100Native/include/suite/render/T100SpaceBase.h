#ifndef T100SPACEBASE_H
#define T100SPACEBASE_H

#include "T100Point.h"
#include "T100Matrix4.h"

class T100SpaceBase
{
    public:
        T100SpaceBase();
        virtual ~T100SpaceBase();

        T100VOID                    SetMatrix(T100FLOAT, T100FLOAT, T100FLOAT);

        virtual T100Point           Translate(T100Point&, T100FLOAT, T100FLOAT, T100FLOAT) = 0;
        virtual T100Point           RevolveX(T100Point&, T100FLOAT) = 0;
        virtual T100Point           RevolveY(T100Point&, T100FLOAT) = 0;
        virtual T100Point           RevolveZ(T100Point&, T100FLOAT) = 0;

    public:
        virtual T100VOID            Translate(T100FLOAT, T100FLOAT, T100FLOAT) = 0;

    protected:

    private:
        T100Matrix4                 m_matrix;

};

#endif // T100SPACEBASE_H
