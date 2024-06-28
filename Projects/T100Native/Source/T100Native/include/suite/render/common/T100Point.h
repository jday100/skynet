#ifndef T100POINT_H
#define T100POINT_H

#include "T100Common.h"
#include "T100VectorV3.h"
#include "T100Matrix4.h"
class T100Point;

T100Point       operator *  (const T100Matrix4&, const T100Point&);

class T100Point
{
    public:
        T100Point();
        virtual ~T100Point();

        T100FLOAT                   m_x         = 0.0;
        T100FLOAT                   m_y         = 0.0;
        T100FLOAT                   m_z         = 0.0;

        T100VOID                    SetValue(T100FLOAT, T100FLOAT, T100FLOAT);

    public:
        T100Point&          operator =  (const T100VectorV3&);

    protected:

    private:
};

#endif // T100POINT_H
