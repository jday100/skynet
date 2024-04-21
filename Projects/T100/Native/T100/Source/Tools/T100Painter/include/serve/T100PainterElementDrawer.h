#ifndef T100PAINTERELEMENTDRAWER_H
#define T100PAINTERELEMENTDRAWER_H

#include <atomic>
#include "T100Common.h"
#include "T100ElementBase.h"
#include "T100ElementInfo.h"
#include "T100DiagramInfo.h"

class T100PainterElementDrawer
{
    public:
        T100PainterElementDrawer();
        virtual ~T100PainterElementDrawer();

        T100BOOL                            Modified();

        T100VOID                            SetDiagramInfo(T100DiagramInfo*);

        T100ElementBase*                    Create();

        T100BOOL                            Select(T100ElementInfo*);

        T100BOOL                            Append(T100ElementBase*);

    protected:
        T100VOID                            create();
        T100VOID                            destroy();

    private:
        std::atomic_bool                    m_modified;
        T100ElementInfo*                    m_current           = T100NULL;
        T100DiagramInfo*                    m_diagram           = T100NULL;
        T100PAINTER_ELEMENT_VECTOR*         m_elements          = T100NULL;
};

#endif // T100PAINTERELEMENTDRAWER_H
