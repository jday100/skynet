#ifndef T100WPAINTER_H
#define T100WPAINTER_H

#include "T100Common.h"
class T100WPainterStore;
class T100WPainterServe;
class T100WPainterView;

class T100WPainter
{
    public:
        T100WPainter();
        virtual ~T100WPainter();

        T100BOOL                    New();
        T100BOOL                    Open();
        T100BOOL                    Close();
        T100BOOL                    Save();
        T100BOOL                    SaveAs();
        T100BOOL                    Quit();

        T100VOID                    setStore(T100WPainterStore*);
        T100WPainterStore*          getStore();

        T100VOID                    setServe(T100WPainterServe*);
        T100WPainterServe*          getServe();

        T100VOID                    setView(T100WPainterView*);
        T100WPainterView*           getView();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100WPainterStore*          m_store         = T100NULL;
        T100WPainterServe*          m_serve         = T100NULL;
        T100WPainterView*           m_view          = T100NULL;
};

#endif // T100WPAINTER_H
