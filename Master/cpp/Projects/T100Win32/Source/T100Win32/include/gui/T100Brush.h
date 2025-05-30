#ifndef T100BRUSH_H
#define T100BRUSH_H

#include "T100Common.h"
#include "T100Win32Common.h"
#include "gui/T100Colour.h"

class T100Brush
{
    public:
        T100Brush();
        T100Brush(T100Colour, T100BRUSH_TYPE = T100BRUSH_TYPE_SOLID);
        T100Brush(T100COLOUR_TYPE = T100COLOUR_TYPE_BLACK, T100BRUSH_TYPE = T100BRUSH_TYPE_SOLID);
        virtual ~T100Brush();

        HBRUSH                  GetHBRUSH();

    protected:
        HBRUSH                  m_brush;

    private:
};

#endif // T100BRUSH_H
