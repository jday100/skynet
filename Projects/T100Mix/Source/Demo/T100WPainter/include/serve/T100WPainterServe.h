#ifndef T100WPAINTERSERVE_H
#define T100WPAINTERSERVE_H

#include <atomic>
#include "T100Common.h"
#include "T100DiagramInfo.h"
#include "T100WPainterElementDrawer.h"

class T100WPainterServe
{
    public:
        T100WPainterServe();
        virtual ~T100WPainterServe();

        T100BOOL                            create();
        T100BOOL                            destroy();

        T100BOOL                            opened();

        T100STRING                          getFileName();
        T100DiagramInfo*                    getDiagramInfo();
        T100WPainterElementDrawer*          getElementDrawer();

    protected:

    private:
        std::atomic_bool                    m_opened;
        T100STRING                          m_filename;
        T100DiagramInfo*                    m_diagram           = T100NULL;
        T100WPainterElementDrawer           m_element_drawer;
};

#endif // T100WPAINTERSERVE_H
