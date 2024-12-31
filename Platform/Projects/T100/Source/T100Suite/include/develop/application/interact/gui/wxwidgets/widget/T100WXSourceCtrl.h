#ifndef T100WXSOURCECTRL_H
#define T100WXSOURCECTRL_H

#include <wx/stc/stc.h>

class T100WXSourceCtrl : public wxStyledTextCtrl
{
    public:
        T100WXSourceCtrl(wxWindow *parent, wxWindowID id=wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxString& name = wxSTCNameStr);
        virtual ~T100WXSourceCtrl();

    protected:

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100WXSOURCECTRL_H
