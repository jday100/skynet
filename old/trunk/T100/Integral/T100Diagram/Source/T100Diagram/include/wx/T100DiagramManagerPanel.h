#ifndef T100DIAGRAMMANAGERPANEL_H
#define T100DIAGRAMMANAGERPANEL_H

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include "T100DiagramElementPanel.h"
#include "T100DiagramEntityPanel.h"

class T100DiagramManagerPanel : public wxPanel
{
    public:
        T100DiagramManagerPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100DiagramManagerPanel();

        T100VOID                            Clear();

    protected:
        static const long ID_NOTEBOOK;

    protected:
        T100UINT                            m_index             = 0;
        wxNotebook*                         m_notebook          = T100NULL;
        T100DiagramElementPanel*            m_elementPanel      = T100NULL;
        T100DiagramEntityPanel*             m_entityPanel       = T100NULL;

    private:
        T100VOID    OnNotebookPageChanged(wxNotebookEvent&);
        T100VOID    OnNotebookPageChanging(wxNotebookEvent&);

        T100VOID                            init();
        T100VOID                            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100DIAGRAMMANAGERPANEL_H
