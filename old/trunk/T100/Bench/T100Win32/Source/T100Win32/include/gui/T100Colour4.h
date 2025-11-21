#ifndef T100COLOUR4_H
#define T100COLOUR4_H

#include "base/T100Class.h"
#include "gui/common/T100GraphicCommon.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Colour4 : public T100Class
{
    public:
        T100Colour4();
        T100Colour4(T100COLOUR4_TYPE);
        virtual ~T100Colour4();

        T100UINT                    GetColour();

        T100VOID                    SetColour4(T100COLOUR4_TYPE);
        T100COLOUR4_TYPE            GetColour4();

        static T100UINT             ToColour(T100COLOUR4_TYPE);

    protected:
        T100COLOUR4_TYPE            m_colour4       = T100COLOUR4_NONE;
        T100UINT                    m_colour        = 0;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100COLOUR4_H
