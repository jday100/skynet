#ifndef T100EDITOR_H
#define T100EDITOR_H

#include <wx/stc/stc.h>
#include "T100Common.h"

class T100Editor : public wxStyledTextCtrl
{
    public:
        T100Editor(wxWindow *parent, wxWindowID id=wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxString& name = wxSTCNameStr);
        virtual ~T100Editor();

    protected:
        T100VOID            OnModified(wxStyledTextEvent&);

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITOR_H
