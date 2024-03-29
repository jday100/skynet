#ifndef T100PAINTER_H
#define T100PAINTER_H

#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100PainterTransverter.h"

namespace T100Painter{
class T100PainterApp;
class T100PainterStore;
class T100PainterServe;
class T100PainterView;


class T100Painter
{
    public:
        T100Painter(T100PainterApp* = T100NULL);
        virtual ~T100Painter();

        T100BOOL                create();

        T100PainterState*       getCurrent();

        T100VOID                reset();

        T100VOID                setStore(T100PainterStore*);
        T100PainterStore*       getStore();

        T100VOID                setServe(T100PainterServe*);
        T100PainterServe*       getServe();

        T100VOID                setView(T100PainterView*);
        T100PainterView*        getView();

        T100VOID                show();
        T100VOID                quit();
        T100VOID                NewFile();

        T100VOID                setParent(wxFrame*);
        T100VOID                setRootFrame(wxMDIParentFrame*);

    protected:
        T100VOID                destroy();

    private:
        T100PainterApp*         m_app           = T100NULL;
        wxFrame*                m_parent        = T100NULL;
        wxMDIParentFrame*       m_root          = T100NULL;
        T100PainterStore*       m_store         = T100NULL;
        T100PainterServe*       m_serve         = T100NULL;
        T100PainterView*        m_view          = T100NULL;

        T100Component::T100PainterTransverter       m_transverter;

};

}

#endif // T100PAINTER_H
