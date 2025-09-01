#ifndef T100PACK_H
#define T100PACK_H

#include <atomic>
#include <wx/panel.h>
#include "T100Common.h"

class T100Pack : public wxPanel
{
    public:
        T100Pack(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100Pack();

        T100VOID                SetIndex(T100INT);
        T100INT                 GetIndex();

    protected:
        std::atomic_int         m_index;

    private:
};

#endif // T100PACK_H
