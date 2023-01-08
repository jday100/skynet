#ifndef T100ELEMENTCIRCLE_H
#define T100ELEMENTCIRCLE_H

#include "T100ElementBase.h"

namespace T100Painter{

class T100ElementCircle : public T100ElementBase
{
    friend class T100ElementCircleSource;
    public:
        T100ElementCircle();
        virtual ~T100ElementCircle();

        T100VOID            Clear();
        T100BOOL            draw(wxDC&);
        T100ElementCircle*  Clone();
        T100BOOL            Hit(T100INT, T100INT);

        T100BOOL            MouseLeftDown(T100INT, T100INT);
        T100BOOL            MouseLeftUp(T100INT, T100INT);
        T100BOOL            MouseMove(T100INT, T100INT);

        T100BOOL            Update(wxPropertyGrid*);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100WORD            m_origin_x;
        T100WORD            m_origin_y;

        T100WORD            m_target_x;
        T100WORD            m_target_y;

        T100FLOAT           m_radius;
};

}

#endif // T100ELEMENTCIRCLE_H
