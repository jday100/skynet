#ifndef T100BRUSH_H
#define T100BRUSH_H

#include "gui/T100Colour4.h"
#include "gui/common/T100WindowCommon.h"

namespace T100WINDOWS{

class T100Brush : public T100Class
{
    public:
        T100Brush(const T100Colour4&, T100BRUSH_TYPE = T100BRUSH_SOLID);
        T100Brush(T100COLOUR4_TYPE = T100COLOUR4_BLACK, T100BRUSH_TYPE = T100BRUSH_SOLID);
        virtual ~T100Brush();

        HBRUSH                      GetHBRUSH();

        T100VOID                    SetColour4(const T100Colour4&);
        const T100Colour4&          GetColour4();

        T100VOID                    SetType(T100BRUSH_TYPE);
        T100BRUSH_TYPE              GetType();

    protected:
        HBRUSH                      m_hbrush        = 0;

        T100Colour4                 m_colour4;
        T100BRUSH_TYPE              m_type;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100BRUSH_H
