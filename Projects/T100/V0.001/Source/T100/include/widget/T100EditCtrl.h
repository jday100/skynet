#ifndef T100EDITCTRL_H
#define T100EDITCTRL_H

#include <wx/stc/stc.h>


class T100EditCtrl : public wxStyledTextCtrl
{
    public:
        T100EditCtrl(wxWindow *parent, wxWindowID id=wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxString& name = wxSTCNameStr);
        virtual ~T100EditCtrl();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T100EDITCTRL_H
