#ifndef T100PLUGINPROJECTPROJECTPANEL_H
#define T100PLUGINPROJECTPROJECTPANEL_H

#include <wx/panel.h>
#include <wx/treectrl.h>
#include "T100Project.h"
#include "T100ProjectInfo.h"

class T100PluginProjectProjectPanel : public wxPanel
{
    public:
        T100PluginProjectProjectPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100PluginProjectProjectPanel();

        T100VOID            Append(T100ProjectInfo&);

        T100VOID            Update(T100PROJECT_VESSEL&);

    protected:
        wxTreeCtrl*         m_treectrl      = T100NULL;

        T100VOID            OnMenu(wxCommandEvent&);
        T100VOID            OnCreate(wxCommandEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PLUGINPROJECTPROJECTPANEL_H
