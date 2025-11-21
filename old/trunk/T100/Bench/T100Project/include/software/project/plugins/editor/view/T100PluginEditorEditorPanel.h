#ifndef T100PLUGINEDITOREDITORPANEL_H
#define T100PLUGINEDITOREDITORPANEL_H

#include <wx/stc/stc.h>
#include <wx/panel.h>
#include "T100Common.h"

class T100PluginEditorEditorPanel : public wxPanel
{
    public:
        T100PluginEditorEditorPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100PluginEditorEditorPanel();

    protected:
        wxStyledTextCtrl*           m_stc       = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100PLUGINEDITOREDITORPANEL_H
