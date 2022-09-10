#ifndef T100VPCDEMOSCREEN_H
#define T100VPCDEMOSCREEN_H

#include <wx/panel.h>


class T100VPCDemoScreen : public wxPanel
{
    public:
        T100VPCDemoScreen(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T100VPCDemoScreen();

    protected:

    private:
};

#endif // T100VPCDEMOSCREEN_H
