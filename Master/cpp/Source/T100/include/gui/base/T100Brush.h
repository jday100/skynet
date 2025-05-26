#ifndef T100BRUSH_H
#define T100BRUSH_H

#include <windows.h>
#include "base/T100Class.h"
#include "gui/common/T100WindowCommon.h"
#include "gui/base/T100Colour.h"

class T100Brush : public T100Class
{
    public:
        T100Brush(T100Colour, T100BRUSH_TYPE = T100BRUSH_SOLID);
        T100Brush(T100COLOUR_TYPE = T100COLOUR_TYPE_BLACK, T100BRUSH_TYPE = T100BRUSH_SOLID);
        virtual ~T100Brush();

        HBRUSH                  GetHBRUSH();

        T100VOID                SetColour(T100Colour);
        T100Colour&             GetColour();

        T100VOID                SetType(T100BRUSH_TYPE);
        T100BRUSH_TYPE&         GetType();

    protected:
        HBRUSH                  m_brush;

        T100Colour              m_colour;
        T100BRUSH_TYPE          m_type;

    private:
};

#endif // T100BRUSH_H
