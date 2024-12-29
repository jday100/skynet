#ifndef T100EDITORCTRL_H
#define T100EDITORCTRL_H

#include <wx/stc/stc.h>

class T100EditorCtrl : public wxStyledTextCtrl
{
    public:
        T100EditorCtrl(wxWindow *parent, wxWindowID id=wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize, long style = 0,
                     const wxString& name = wxSTCNameStr);
        virtual ~T100EditorCtrl();

    protected:
        static const long ID_STC_MODIFIED;

        void OnModified(wxStyledTextEvent& event);

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T100EDITORCTRL_H
