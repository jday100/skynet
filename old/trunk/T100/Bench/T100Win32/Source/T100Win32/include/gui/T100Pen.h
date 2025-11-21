#ifndef T100PEN_H
#define T100PEN_H

#include "gui/T100Colour4.h"
#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

class T100Pen : public T100Class
{
    public:
        T100Pen(const T100Colour4&, T100UINT = 1, T100LINE_TYPE = T100LINE_SOLID);
        T100Pen(T100COLOUR4_TYPE = T100COLOUR4_BLACK, T100UINT = 1, T100LINE_TYPE = T100LINE_SOLID);
        virtual ~T100Pen();

        HPEN                        GetHPEN();

        T100VOID                    SetColour4(const T100Colour4&);
        const T100Colour4&          GetColour4();

        T100VOID                    SetType(T100LINE_TYPE);
        T100LINE_TYPE               GetType();

        T100VOID                    SetWidth(T100UINT);
        T100UINT                    GetWidth();

    protected:
        HPEN                        m_hpen;
        T100UINT                    m_width         = 1;
        T100Colour4                 m_colour4;
        T100LINE_TYPE               m_type          = T100LINE_NONE;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100PEN_H
