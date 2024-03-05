#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include <wx/window.h>
#include <wx/aui/aui.h>
#include "T100String.h"
#include "T100WxApp.h"
#include "T100ProjectProjectsPanel.h"


namespace T100PROJECT{

class T100ProjectView
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();


    public:
        T100VOID                        setParent(wxWindow*);
        T100VOID                        setRootFrame(wxFrame*);

        T100VOID                        setMenu(wxFrame*);
        T100VOID                        setManager(wxAuiManager*);

        T100BOOL                        create();

        T100VOID                        show();

    protected:
        T100VOID                        destroy();

    private:
        wxWindow*                       m_parent            = T100NULL;
        wxAuiManager*                   m_manager           = T100NULL;

};

}

#endif // T100PROJECTVIEW_H
