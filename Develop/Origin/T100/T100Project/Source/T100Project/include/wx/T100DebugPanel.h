#ifndef T100DEBUGPANEL_H
#define T100DEBUGPANEL_H

#include <wx/textctrl.h>
#include "T100Common.h"

class T100DebugPanel : public wxTextCtrl
{
    public:
        T100DebugPanel(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTE_MULTILINE,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);
        virtual ~T100DebugPanel();

        virtual T100BOOL            Append(const T100WSTRING&);

    protected:
        T100VOID                    OnMouseRightDown(wxMouseEvent&);

        T100VOID                    OnClear(wxCommandEvent&);

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100DEBUGPANEL_H
