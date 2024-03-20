#ifndef T100PAINTER_H
#define T100PAINTER_H

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"

class T100Painter
{
    public:
        T100Painter();
        virtual ~T100Painter();

        T100VOID                    setStore(T100PainterStore*);
        T100PainterStore*           getStore();
        T100VOID                    setServe(T100PainterServe*);
        T100PainterServe*           getServe();
        T100VOID                    setView(T100PainterView*);
        T100PainterView*            getView();

    public:
        T100BOOL                    Opened();
        T100BOOL                    Open();
        T100BOOL                    Close();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100PainterStore*           m_store         = T100NULL;
        T100PainterServe*           m_serve         = T100NULL;
        T100PainterView*            m_view          = T100NULL;
};

#endif // T100PAINTER_H
