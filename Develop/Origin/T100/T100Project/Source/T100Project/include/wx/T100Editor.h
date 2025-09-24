#ifndef T100EDITOR_H
#define T100EDITOR_H

#include <atomic>
#include <wx/stc/stc.h>
#include "T100Common.h"

class T100Editor : public wxStyledTextCtrl
{
    public:
        T100Editor(wxWindow *parent, wxWindowID id=wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxSize(0, 0), long style = wxTE_PROCESS_TAB,
                     const wxString& name = wxSTCNameStr);
        virtual ~T100Editor();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

        T100VOID                Lock();
        T100VOID                Unlock();

    protected:
        std::atomic_bool        m_flag;
        T100WSTRING             m_path;

        T100VOID                OnModified(wxStyledTextEvent&);

    private:
        T100VOID                init();
        T100VOID                uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITOR_H
