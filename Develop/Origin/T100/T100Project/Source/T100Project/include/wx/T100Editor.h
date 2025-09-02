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

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

    protected:
        T100VOID                OnModified(wxStyledTextEvent&);\
        T100WSTRING             m_path;

    private:
        T100VOID                init();
        T100VOID                uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITOR_H
