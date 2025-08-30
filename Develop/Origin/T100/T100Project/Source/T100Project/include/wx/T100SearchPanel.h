#ifndef T100SEARCHPANEL_H
#define T100SEARCHPANEL_H

#include <wx/listctrl.h>

class T100SearchPanel : public wxListView
{
    public:
        T100SearchPanel(wxWindow *parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxLC_REPORT,
                const wxValidator& validator = wxDefaultValidator,
                const wxString &name = wxListCtrlNameStr);
        virtual ~T100SearchPanel();

    protected:

    private:
};

#endif // T100SEARCHPANEL_H
