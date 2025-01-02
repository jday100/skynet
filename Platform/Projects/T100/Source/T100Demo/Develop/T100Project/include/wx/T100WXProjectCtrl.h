#ifndef T100WXPROJECTCTRL_H
#define T100WXPROJECTCTRL_H

#include <wx/treectrl.h>

class T100WXProjectCtrl : public wxTreeCtrl
{
    public:
        T100WXProjectCtrl(wxWindow *parent, wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTreeCtrlNameStr);
        virtual ~T100WXProjectCtrl();

    protected:

    private:
};

#endif // T100WXPROJECTCTRL_H
