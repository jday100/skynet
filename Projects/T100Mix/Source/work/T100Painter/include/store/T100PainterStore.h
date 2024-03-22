#ifndef T100PAINTERSTORE_H
#define T100PAINTERSTORE_H

#include "T100Common.h"
#include "wx\paint\diagram\T100DiagramDrawer.h"

class T100PainterStore
{
    public:
        T100PainterStore();
        virtual ~T100PainterStore();

        T100BOOL                    OpenFile();

        T100BOOL                    SaveFile();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100DiagramDrawer*          m_diagram_drawer            = T100NULL;
};

#endif // T100PAINTERSTORE_H
