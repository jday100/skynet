#ifndef T100ELEMENTCIRCLE_H
#define T100ELEMENTCIRCLE_H

#include "T100ElementBase.h"

class T100ElementCircle : public T100ElementBase
{
    friend class T100ElementCircleSource;
    public:
        T100ElementCircle();
        virtual ~T100ElementCircle();

        T100BOOL            Draw(wxDC&);

        T100VOID            SetStartingPoint(T100INT, T100INT);
        T100VOID            SetTerminalPoint(T100INT, T100INT);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100INT             m_origin_x;
        T100INT             m_origin_y;

        T100INT             m_target_x;
        T100INT             m_target_y;

        T100FLOAT           m_radius;
};

#endif // T100ELEMENTCIRCLE_H
