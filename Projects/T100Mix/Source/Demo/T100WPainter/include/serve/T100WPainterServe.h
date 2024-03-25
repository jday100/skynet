#ifndef T100WPAINTERSERVE_H
#define T100WPAINTERSERVE_H

#include "T100Common.h"
#include "T100DiagramInfo.h"

class T100WPainterServe
{
    public:
        T100WPainterServe();
        virtual ~T100WPainterServe();

        T100BOOL                    create();
        T100BOOL                    destroy();

        T100DiagramInfo*            getDiagramInfo();

    protected:

    private:
        T100DiagramInfo*            m_diagram           = T100NULL;
};

#endif // T100WPAINTERSERVE_H
