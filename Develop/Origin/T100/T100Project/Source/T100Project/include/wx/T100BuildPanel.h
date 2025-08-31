#ifndef T100BUILDPANEL_H
#define T100BUILDPANEL_H

#include <wx/textctrl.h>
#include "T100Common.h"

class T100BuildPanel : public wxTextCtrl
{
    public:
        T100BuildPanel(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTE_MULTILINE,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);
        virtual ~T100BuildPanel();

        virtual T100BOOL            Append(const T100WSTRING&);

    protected:
        T100VOID                    OnMouseRightDown(wxMouseEvent&);

        T100VOID                    OnClear(wxCommandEvent&);

    private:
        T100VOID                    init();
        T100VOID                    uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100BUILDPANEL_H
