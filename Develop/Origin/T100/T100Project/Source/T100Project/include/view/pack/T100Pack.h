#ifndef T100PACK_H
#define T100PACK_H

#include <wx/panel.h>
#include "T100Common.h"

class T100Pack : public wxPanel
{
    public:
        T100Pack(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxSize(0, 0),
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100Pack();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

    protected:
        T100WSTRING             m_label;
        T100WSTRING             m_path;

    private:
};

#endif // T100PACK_H
