#ifndef T100PAINTERELEMENTSDRAWER_H
#define T100PAINTERELEMENTSDRAWER_H

#include "T100ElementBase.h"

class T100PainterElementsDrawer
{
    public:
        T100PainterElementsDrawer();
        virtual ~T100PainterElementsDrawer();

        T100ElementBase*            Current();
        T100VOID                    Deselect();

    protected:

    private:
        T100ElementBase*            m_current           = T100NULL;
};

#endif // T100PAINTERELEMENTSDRAWER_H
