#ifndef T100PAINTER_H
#define T100PAINTER_H

#include "T100Common.h"
class T100PainterStore;
class T100PainterServe;
class T100PainterView;

class T100Painter
{
    public:
        T100Painter();
        virtual ~T100Painter();

        T100BOOL                    New();
        T100BOOL                    Open();
        T100BOOL                    Close();
        T100BOOL                    Save();
        T100BOOL                    SaveAs();
        T100BOOL                    Quit();


    public:
        T100VOID                    setStore(T100PainterStore*);
        T100PainterStore*           getStore();

        T100VOID                    setServe(T100PainterServe*);
        T100PainterServe*           getServe();

        T100VOID                    setView(T100PainterView*);
        T100PainterView*            getView();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100VOID                    init();

    private:
        T100PainterStore*           m_store         = T100NULL;
        T100PainterServe*           m_serve         = T100NULL;
        T100PainterView*            m_view          = T100NULL;
};

#endif // T100PAINTER_H
