#ifndef T1003DEDITORENTITYPANEL_H
#define T1003DEDITORENTITYPANEL_H

#include <wx/panel.h>

class T1003DEditorEntityPanel : public wxPanel
{
    public:
        T1003DEditorEntityPanel(wxWindow *parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorEntityPanel();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORENTITYPANEL_H
