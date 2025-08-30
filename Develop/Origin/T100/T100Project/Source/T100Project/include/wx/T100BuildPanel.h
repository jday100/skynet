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
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);
        virtual ~T100BuildPanel();

        virtual T100BOOL            Append(const T100WSTRING&);

    protected:

    private:
};

#endif // T100BUILDPANEL_H
