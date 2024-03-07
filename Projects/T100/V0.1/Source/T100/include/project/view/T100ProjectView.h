#ifndef T100PROJECTVIEW_H
#define T100PROJECTVIEW_H

#include <wx/window.h>
#include <wx/aui/aui.h>
#include "T100String.h"
#include "T100WxApp.h"
#include "T100ProjectProjectsPanel.h"

#include "T100MansionInfo.h"


namespace T100PROJECT{
class T100ProjectFrame;


class T100ProjectView
{
    public:
        T100ProjectView();
        virtual ~T100ProjectView();

        T100BOOL                        OpenFile(T100STRING&);
        T100BOOL                        CloseFile();

        T100BOOL                        LoadFile(T100MansionInfo*);

        T100BOOL                        Quit();
        T100BOOL                        UpdateMenu();
        T100BOOL                        ShowProjects();

        T100BOOL                        create_alone();
        T100BOOL                        create_embed();

        T100ProjectProjectsPanel*       getProjectCtrl();

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
        wxWindow*                       m_parent                = T100NULL;
        wxAuiManager*                   m_manager               = T100NULL;

        T100ProjectFrame*               m_frame                 = T100NULL;
        wxFrame*                        m_root                  = T100NULL;

        T100ProjectProjectsPanel*       m_projects_panel        = T100NULL;

        wxFrame*                                m_callback_frame        = T100NULL;
        T100WxWidgets::T100FRAME_CALLBACK       m_callback              = T100NULL;

};

}

#endif // T100PROJECTVIEW_H
