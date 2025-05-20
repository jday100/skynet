#ifndef T100PEN_H
#define T100PEN_H

#include "T100Common.h"
#include "T100Win32Common.h"
#include "gui/T100Colour.h"

class T100Pen
{
    public:
        T100Pen();
        T100Pen(T100Colour, T100WORD = 1, T100LINE_TYPE = T100LINE_SOLID);
        T100Pen(T100COLOUR_TYPE = T100COLOUR_TYPE_BLACK, T100WORD = 1, T100LINE_TYPE = T100LINE_SOLID);
        virtual ~T100Pen();

        HPEN            GetHPEN();

    protected:
        HPEN            m_pen;

    private:
};

#endif // T100PEN_H
