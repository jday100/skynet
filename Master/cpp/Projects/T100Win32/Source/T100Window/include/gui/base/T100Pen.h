#ifndef T100PEN_H
#define T100PEN_H

#include <windows.h>
#include "base/T100Class.h"
#include "T100Common.h"
#include "gui/common/T100WindowCommon.h"
#include "gui/base/T100Colour.h"

class T100Pen : public T100Class
{
    public:
        T100Pen(T100Colour, T100WORD = 1, T100LINE_TYPE = T100LINE_SOLID);
        T100Pen(T100COLOUR_TYPE = T100COLOUR_TYPE_BLACK, T100WORD = 1, T100LINE_TYPE = T100LINE_SOLID);
        virtual ~T100Pen();

        HPEN                    GetHPEN();

        T100VOID                SetColour(T100Colour);
        T100Colour&             GetColour();

        T100VOID                SetType(T100LINE_TYPE);
        T100LINE_TYPE&          GetType();

        T100VOID                SetWidth(T100WORD);
        T100WORD                GetWidth();

    protected:
        HPEN                    m_pen;
        T100WORD                m_width         = 1;
        T100Colour              m_colour;
        T100LINE_TYPE           m_type;

    private:
        T100VOID                Init();
};

#endif // T100PEN_H
