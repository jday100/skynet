#ifndef T100PROJECT_H
#define T100PROJECT_H

#include <wx/docmdi.h>
#include "T100ProjectCommon.h"
#include "T100ProjectTransverter.h"

namespace T100PROJECT{
class T100ProjectApp;
class T100ProjectStore;
class T100ProjectServe;
class T100ProjectView;


class T100Project
{
    public:
        T100Project(T100ProjectApp* = T100NULL);
        virtual ~T100Project();

        T100BOOL                create();

        T100VOID                reset();

        T100VOID                setStore(T100ProjectStore*);
        T100ProjectStore*       getStore();

        T100VOID                setServe(T100ProjectServe*);
        T100ProjectServe*       getServe();

        T100VOID                setView(T100ProjectView*);
        T100ProjectView*        getView();

        T100VOID                show();
        T100VOID                quit();
        T100VOID                NewFile();

        T100VOID                setParent(wxFrame*);
        T100VOID                setRootFrame(wxMDIParentFrame*);

    protected:
        T100VOID                destroy();

    private:
        T100ProjectApp*         m_app           = T100NULL;
        wxFrame*                m_parent        = T100NULL;
        wxMDIParentFrame*       m_root          = T100NULL;
        T100ProjectStore*       m_store         = T100NULL;
        T100ProjectServe*       m_serve         = T100NULL;
        T100ProjectView*        m_view          = T100NULL;

        T100Component::T100ProjectTransverter       m_transverter;
};

}

#endif // T100PROJECT_H
