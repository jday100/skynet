#ifndef T100COMPILEPANEL_H
#define T100COMPILEPANEL_H

#include <wx/textctrl.h>
#include "T100Common.h"

class T100CompilePanel : public wxTextCtrl
{
    public:
        T100CompilePanel(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTE_MULTILINE,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);
        virtual ~T100CompilePanel();

        virtual T100BOOL            Append(const T100WSTRING&);

    protected:
        T100VOID                    OnMouseRightDown(wxMouseEvent&);

        T100VOID                    OnClear(wxCommandEvent&);

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100COMPILEPANEL_H
