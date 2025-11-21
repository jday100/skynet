#ifndef T1003DEDITORMANAGERPANEL_H
#define T1003DEDITORMANAGERPANEL_H

#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/notebook.h>
#include "T1003DEditorScenePanel.h"
#include "T1003DEditorSurfacePanel.h"
#include "T1003DEditorEntityPanel.h"


class T1003DEditorManagerPanel : public wxPanel
{
    public:
        T1003DEditorManagerPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorManagerPanel();

        T1003DEditorScenePanel*         GetScenePanel();
        T1003DEditorSurfacePanel*       GetSurfacePanel();
        T1003DEditorEntityPanel*        GetEntityPanel();

    protected:
        T1003DEditorScenePanel*         m_scenePanel        = T100NULL;
        T1003DEditorSurfacePanel*       m_surfacePanel      = T100NULL;
        T1003DEditorEntityPanel*        m_entityPanel       = T100NULL;

    private:
        T100VOID            OnEnterWindow(wxMouseEvent& event);
        T100VOID            OnLeaveWindow(wxMouseEvent& event);

    private:
        wxNotebook*                     m_notebook          = T100NULL;
        wxImageList*                    m_imageList         = T100NULL;

        T100VOID                        initImageList();

        T100VOID                        init();
        T100VOID                        uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMANAGERPANEL_H
