#ifndef T100WPAINTERELEMENTDRAWER_H
#define T100WPAINTERELEMENTDRAWER_H

#include "T100Common.h"
#include "T100ElementBase.h"
#include "T100ElementInfo.h"
#include "T100DiagramInfo.h"

class T100WPainterElementDrawer
{
    public:
        T100WPainterElementDrawer();
        virtual ~T100WPainterElementDrawer();

        T100VOID                            SetDiagramInfo(T100DiagramInfo*);

        T100ElementBase*                    Create();

        T100BOOL                            Select(T100ElementInfo*);

        T100BOOL                            Append(T100ElementBase*);

    protected:

    private:
        T100ElementInfo*                    m_current           = T100NULL;
        T100DiagramInfo*                    m_diagram           = T100NULL;
        T100WPAINTER_ELEMENT_VECTOR*        m_elements          = T100NULL;
};

#endif // T100WPAINTERELEMENTDRAWER_H
