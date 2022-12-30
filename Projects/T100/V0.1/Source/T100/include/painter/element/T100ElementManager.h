#ifndef T100ELEMENTMANAGER_H
#define T100ELEMENTMANAGER_H

#include "T100PainterCommon.h"

namespace T100Painter{

class T100ElementManager
{
    public:
        T100ElementManager();
        virtual ~T100ElementManager();

        T100VOID            init();

        T100BOOL            Append(T100ElementBase*);

        T100BOOL            Select(T100STRING);
        T100ElementBase*    GetCurrent();

    protected:

    private:
        T100ElementBase*                m_current           = T100NULL;

        T100PAINTER_ELEMENT_HASH        m_elements;

};

}

#endif // T100ELEMENTMANAGER_H
