#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include <atomic>
#include "T100Common.h"
#include "T100DiagramInfo.h"
#include "T100PainterElementDrawer.h"
#include "T100PainterElementsDrawer.h"

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100BOOL                            opened();
        T100BOOL                            modified();

        T100STRING                          getFileName();
        T100DiagramInfo*                    getDiagramInfo();
        T100PainterElementDrawer*           getElementDrawer();
        T100PainterElementsDrawer*          getElementsDrawer();

    protected:
        T100VOID                            create();
        T100VOID                            destroy();

    private:
        std::atomic_bool                    m_opened;
        T100STRING                          m_filename;
        T100DiagramInfo*                    m_diagram           = T100NULL;
        T100PainterElementDrawer            m_element_drawer;
        T100PainterElementsDrawer           m_elements_drawer;
};

#endif // T100PAINTERSERVE_H
