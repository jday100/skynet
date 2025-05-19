#ifndef T100COLOUR_H
#define T100COLOUR_H

#include "T100Common.h"
#include "base/T100Class.h"
#include "common/T100GraphicCommon.h"

class T100Colour : public T100Class
{
    public:
        T100Colour();
        T100Colour(T100COLOUR_TYPE);
        T100Colour(T100BYTE, T100BYTE, T100BYTE, T100BYTE = 0);
        virtual ~T100Colour();

        T100DWORD                   GetColour();

        static T100DWORD            Colour(T100COLOUR_TYPE);

    protected:
        T100DWORD                   m_colour            = 0;

    private:
};

#endif // T100COLOUR_H
