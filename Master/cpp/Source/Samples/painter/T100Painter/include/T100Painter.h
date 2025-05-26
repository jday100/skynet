#ifndef T100PAINTER_H
#define T100PAINTER_H

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"

class T100Win32Application;

class T100Painter
{
    public:
        T100Painter();
        virtual ~T100Painter();

        T100VOID                    Create(T100Win32Application*);

        T100PainterStore&           GetStore();
        T100PainterServe&           GetServe();
        T100PainterView&            GetView();

    public:
        T100VOID                    New();
        T100VOID                    Quit();

        T100VOID                    Resize();

    protected:

    private:
        T100PainterStore            m_store;
        T100PainterServe            m_serve;
        T100PainterView             m_view;

        T100VOID                    init(T100Win32Application*);
        T100VOID                    uninit();
};

#endif // T100PAINTER_H
